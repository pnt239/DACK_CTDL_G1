#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX 100
#define VOCUC 32760


class Place
{
private:
	int n;
	int L[MAX][MAX];
public:
	void ReadFile(string fileName);
	void Creat(int T[], int label[],int length[], int A);
	void PathFind(int T[], int label[],int length[], int A, int C);
	int Cost();
	void List();
};