#pragma once 
#include<string>
using namespace std;
class NO520
{
public:
	NO520();
	~NO520();

	bool isCap(char a,int A,int Z)
	{   int temp =(int)a;
		if(a>=A&&a<=Z)
		{
			return true;
		}
		return false;
	}
    bool detectCapitalUse(string word) {
		int A=(int)"A";
		int Z=(int)"Z";
		//int n=strlen(word);
		if(isCap(word[0],A,Z))
		{   if(word.length>1)
			{bool result =isCap(word[1],A,Z);
			for (int i = 1; i < word.length; i++)
			{
				if(isCap(word[i],A,Z)!=result)
					return false;
			}
		}
		}
		else
		{
			for (int i = 1; i < word.length; i++)
			{
			    if(isCap(word[i],A,Z))
				{
					return false;
				}
			}
		}
		return true;
    }

private:

};

NO520::NO520()
{
}

NO520::~NO520()
{
}