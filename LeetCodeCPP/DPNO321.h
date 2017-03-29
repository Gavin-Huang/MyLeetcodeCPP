#pragma once 
#include<vector>
using namespace std;
class DPNO321
{
public:
	DPNO321();
	~DPNO321();
		int compare(vector<int>& s1,vector<int>& s2)
	{  

		if(s1.size()*s2.size()>0)
		{
			if(s1[0]*s2[0]>0)
			{
				if(s1.size()<s2.size())
				{
					return 1;
				}
				else if(s1.size()==s2.size())
				{
					int i=0;
					while (i<s1.size()&&s1[i]==s2[i])
					{
						i++;
					}
					if(i==s1.size())
					{
						return 0;
					}
					if(s1[i]<s2[i])
					{
						return 1;
					}
					else if(s1[i]<s2[i])
					{
						return -1;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return -1;
				}
			}
			else
			{
				if(s1[0]==0&&s2[0]!=0)
					return 1;
				if(s1[0]!=0&&s2[0]==0)
					return -1;
				return 0;
			}

		}
		else
		{
			if(s1.size()==0&&s2.size()!=0&&s2[0]!=0)
			{
				return 1;
			}
			if(s1.size()!=0&&s1[0]!=0&&s2.size()==0)
			{
				return -1;
			}
			return 0;
		}
	}
	vector<int> Max(int i,int j,int kc,vector<int>& s1,vector<int>& s2)
	{   vector<int> ten;
		if(i+j!=kc) return ten;
		
		auto value=Max(i-1,j,kc-1,s1,s2);
		value.push_back(s1[i]);
		
		auto value2=Max(i,j-1,kc-1,s1,s2);
		value2
	}
	void test()
	{

	}
private:

};

DPNO321::DPNO321()
{
}

DPNO321::~DPNO321()
{
}