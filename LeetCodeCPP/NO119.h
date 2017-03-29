#pragma once
#include<vector>
using namespace std;
class NO119

{
public:
	NO119
();
	~NO119
();
	vector<int> getRow(int rowIndex) {
		vector<int> reslut;
		long long int k =rowIndex;long long  int n=0;
		long long int temp=0;
		for (int i = 0; i < rowIndex+1; i++)
		{   n=i;
			if(i>k/2)
				n=k-i;
			if(n!=0)
			temp =reslut[n-1];
			int m =n==0?1:temp*(k-n+1)/n;
			reslut.push_back(m);
		}
		return reslut;
    }
   /*	long long int D(vector<int> d, int c,int in)
	{  
		if(in>c/2)
		{
			return D( c,c-in);
		}
		long double Reslut=1;
		for (long double i = 1; i < in+1; i++)
		{
			Reslut*=(c-i+1)/(in+1-1);
		}
		return (long long int)Reslut;
	}*/
 /* long long int P(int in)
	{
	 long long int result=1;
	   for ( long long int i = 1; i < in+1; i++)
	   {
		   result*=(i);
	   }
	   return result;
	}*/
	void  Test()
	{
NO119 gg;
gg.getRow(30);
	}
private:

};

NO119
::NO119
()
{
}

NO119
::~NO119
()
{
}