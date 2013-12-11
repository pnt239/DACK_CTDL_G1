#include <iostream>
#include <List.h>
using namespace std;

int main()
{
	CList<int> a;
	a.push(10);
	a.push(20);
	cout<<a[0]<<" "<<a[1]<<endl;
	return 0;
}