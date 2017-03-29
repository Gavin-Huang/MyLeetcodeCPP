#pragma once
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class NO412
{
public:
	NO412();
	~NO412();
	 vector<string> fizzBuzz(int n) {
        vector<string> result;
		for (int i = 1; i < n+1; i++)
		{
			if(i%15==0)
			{
				result.push_back("FizzBuzz");
			}
			else
			{
				if(i%3==0)
				{
					result.push_back("Fizz");
				}
				else if(i%5==0)
				{
				   result.push_back("Buzz");
				}
				else
				{    
					result.push_back(to_string(i));
				}
			}
		}
		return result;
    }
	 void test()
	 {
		 fizzBuzz(16);
	 }
private:

};

NO412::NO412()
{
}

NO412::~NO412()
{
}