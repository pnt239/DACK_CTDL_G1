// LZW.h
//
//////////////////////////////////////////////////////////////////////

#if !defined(__LZW_H__)
#define __LZW_H__

bool CompressLZW(BYTE *pSrc, int nSrcLen, BYTE *&pDes, int &nDesLen, int nBitsPerSample = 12);
bool DecompressLZW(BYTE *pSrc, int nSrcLen, BYTE *&pDes, int &nDesLen);

#endif __LZW_H__
