// LeetCodeCPP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"NO345.h"
#include"NO321.h"
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include <memory>
#include<set>
using namespace std;
//#define Fun1(a,b) a+b
//#define Fun2(a,b) *b+a
//#define Fun3(a,b) a^b
//#define Fun4(a,b) a-b
//int nA=1;
//int nB=2;
//int nFun=Fun1(nA,nB)Fun2(nA,nB)-Fun3(nA,nB)*Fun4(nA,nB);

int _tmain(int argc, _TCHAR* argv[])
{  
	set<int> result;
	int n;
	cin>>n;
	while (n--)
	{   
		cin>>n;
		result.insert(n);

	}

	system("pause");
	return 0;
}

