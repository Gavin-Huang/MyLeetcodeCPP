#pragma once
#include<String>
using namespace std;
class NO344
{
public:
	NO344();
	~NO344();
	 string reverseString(string s) {
		 int c=s.length();
		 char* ress=new char[c+1];
		/* return s.*/
		
		 for (int i = c-1; i >=0 ; i--)
		 {   
           ress[c-1-i]=s[i];
		 }
		 ress[c]='\0';
		 return ress;
    }
	 void test()
	 {
		 reverseString("string");
	 }
private:

};

NO344::NO344()
{
}

NO344::~NO344()
{
}