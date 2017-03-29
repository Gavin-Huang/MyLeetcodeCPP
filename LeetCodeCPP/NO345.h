#pragma once
#include<string>
using namespace std;
class NO345
{
public:
	NO345();
	~NO345();
	 string reverseVowels(string s) {
         int c=s.length();
		 char* ress=new char[c+1];
		/* return s.*/
		 for (int i = c-1; i >=0 ; i--)
		 { 
			 if(isVowels(s[i])&&isVowels(s[c-1-i]))
           ress[c-1-i]=s[i];
			 else  ress[c-1-i]=s[c-1-i];
		 }
		 ress[c]='\0';
		 return ress;
    }
	 bool isVowels(char a)
	 {
		 if(a == 'a'||a=='e'||a=='i'||a=='o'||a=='u')
		 {
			 return true;
		 }
		 return false;
	 }
	  void test()
	 {
		 reverseVowels("leetcode");
	 }
private:

};

NO345::NO345()
{
}

NO345::~NO345()
{
}