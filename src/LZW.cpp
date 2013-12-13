// LZW.cpp: implementation of the LZW class.
//
//////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include "BinaryTree.h"

//////////////////////////////////////////////////////////////////////
class CBuffer
{
public:
	CBuffer()	{}
	CBuffer(BYTE* pBuffer, int nLength) { m_pBuffer = pBuffer, m_nLength = nLength;	}
	CBuffer(const CBuffer& buffer) { *this = buffer;	}

public:
	BYTE* m_pBuffer;
	int m_nLength;
	inline int compare(const CBuffer* buffer)
	{
		int nResult = memcmp(m_pBuffer, buffer->m_pBuffer, min(m_nLength, buffer->m_nLength));
		if(nResult != 0 || m_nLength == buffer->m_nLength)
			return nResult;
		return m_nLength > buffer->m_nLength ? 1 : -1;
	}
	inline void operator=(const CBuffer* buffer) { m_pBuffer = buffer->m_pBuffer;	m_nLength = buffer->m_nLength;	}
};

void *AllocPtr(int nSize)
{
	void *p = malloc(nSize);
	return memset(p, 0, _msize(p));
}

void *ReAllocPtr(void *p, int nSize)
{
	int nOldSize = _msize(p);
	p = realloc(p, nSize);
	if(nSize > nOldSize)
	{
		nSize = _msize(p);
		memset((char*)p+nOldSize, 0, nSize-nOldSize);
	}
	return p;
}

void FreePtr(void *p)
{
	free(p);
}

bool CompressLZW(BYTE *pSrc, int nSrcLen, BYTE *&pDes, int &nDesLen, int nBitsPerSample)
{
	nDesLen = (sizeof(DWORD)+1)<<3;
	// allocate buffer for destination buffer
	int nAllocLength = nSrcLen*2;
	pDes = (BYTE*)AllocPtr(nAllocLength);
	// save source buffer length at the first DWORD
	*(DWORD*)pDes = nSrcLen;
	*(pDes+sizeof(DWORD)) = nBitsPerSample;
	int nSample = *pSrc;
	int nMaxSamples = 1 << nBitsPerSample;
	// dictionary hash table
	CBinaryTree<CBuffer, CBuffer*, int, int> dictionary;
	dictionary.NoRepeat = true;
	// keep first 256 IDs for ascii Samples
	dictionary.Serial = 256;
	// tree node to keep last success search to start with
	CBinaryTreeNode<CBuffer, int>* pNode = dictionary.Root;
	// left dictionary Samples points to the source buffer
	CBuffer node(pSrc, 2);
	// scan the input buffer
	while(nSrcLen-- > 0)
	{
		if(dictionary.Serial == nMaxSamples)
		{
			dictionary.RemoveAll();
			dictionary.Serial = 256;
		}
		pNode = dictionary.Insert(&node, -1, pNode);
		if(pNode->Count > 1 && nSrcLen)
			// (repeated Sample), save success Sample to be used next fail
			nSample = pNode->ID, node.m_nLength++;
		else
		{	// write last success Sample
			if((nDesLen>>3)+(int)sizeof(DWORD) >= nAllocLength)
				pDes = (BYTE*)ReAllocPtr(pDes, nAllocLength += 100);
			*(DWORD*)(pDes+(nDesLen>>3)) |= nSample << (nDesLen&7);
			nDesLen += nBitsPerSample;
			// initialize node to next Sample
			node.m_pBuffer += node.m_nLength-1;
			node.m_nLength = 2;
			// copy first byte of the node as a new Sample
			if(nSrcLen > 0)
				nSample = *node.m_pBuffer;
			// initialize search root
			pNode = dictionary.Root;
		}
	}
	nDesLen = (nDesLen+7)/8;
	pDes = (BYTE*)ReAllocPtr(pDes, nDesLen);

	return true;
}

void ClearDictionary(vector<CBuffer *>& dictionary)
{
	for(vector<CBuffer*>::iterator i = dictionary.begin(); i != dictionary.end(); i++)
		delete (*i);
	dictionary.clear();
}

bool DecompressLZW(BYTE *pSrc, int nSrcLen, BYTE *&pDes, int &nDesLen)
{	// first two DWORDS (final buffer length, Samples sizes bitmap buffer start)
	// copy destination final length
	nDesLen = *(DWORD*)pSrc;
	// copy bits pre Sample
	int nBitsPerSample = *(pSrc+sizeof(DWORD));
	// allocate buffer for decompressed buffer
	pDes = (BYTE*)malloc(nDesLen+1);
	// copy first char from source to destination
	*pDes = *(pSrc+sizeof(DWORD)+1);
	int nMaxSamples = 1 << nBitsPerSample;
	int nSample, nSrcIndex = ((sizeof(DWORD)+1)<<3) + nBitsPerSample;
	// dictionary array
	vector<CBuffer *> dictionary;
	// let dictionary Samples points to the destination buffer
	CBuffer node(pDes, 2), *pNodeSample;
	int nDesIndex = 1, nDesIndexSave = 0, nSampleLen;

	while(nDesIndex < nDesLen)
	{
		nSample = (*(DWORD*)(pSrc+(nSrcIndex>>3)))>>(nSrcIndex&7) & (nMaxSamples-1);
		nSrcIndex += nBitsPerSample;

		if(dictionary.size() == nMaxSamples-256)
			ClearDictionary(dictionary);

		if(nSample >= 256)
			if(nSample-256 < (int)dictionary.size())
			{	// normal case, valid dictionary Sample
				nDesIndexSave = nDesIndex;
				pNodeSample = dictionary.at(nSample-256);
				nSampleLen = pNodeSample->m_nLength+1;
				// copy dictionary node buffer to decompressed buffer
				memcpy(pDes+nDesIndex, pNodeSample->m_pBuffer, pNodeSample->m_nLength);
				nDesIndex += pNodeSample->m_nLength;
			}
			else
			{	// out of range Sample
				nSampleLen = nDesIndex-nDesIndexSave+2;
				// copy previous decompressed Sample as a new one + ...
				memcpy(pDes+nDesIndex, pDes+nDesIndexSave, nDesIndex-nDesIndexSave);
				nDesIndex += nDesIndex-nDesIndexSave;
				// add first char of the previous decompressed Sample
				*(pDes+nDesIndex++) = *(pDes+nDesIndexSave);
				nDesIndexSave += nSampleLen-2;
			}
		else
			nDesIndexSave = nDesIndex, *(pDes+nDesIndex++) = (BYTE)nSample, nSampleLen = 2;

		// add current segment to the dictionary
		dictionary.push_back(new CBuffer(node));
		// increment next node pointer to the last char of the added Sample
		node.m_pBuffer += node.m_nLength-1;
		node.m_nLength = nSampleLen;
	}
	// free dictionary Samples
	ClearDictionary(dictionary);

	return true; 
}
