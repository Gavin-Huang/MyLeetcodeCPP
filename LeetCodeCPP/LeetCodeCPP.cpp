// LeetCodeCPP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   int i=0;
	while(cin>>i)
	{
	Solution* g=new Solution();
	cout<<g->findComplement(i)<<endl;
	}
	system("pause");
	return 0;
}

