#ifndef _Solution
#define _Solution
#include<vector>
#include   <map> 
using namespace std;
class Solution {
public:
	Solution()
	{}
    int findComplement(int num) {
		int p=1;
		/*bool* Indexs=new bool[32];*/
		bool Indexs[32];
		for (int i = 0; i <32 ; i++)
		{
			Indexs[i]=(num&p)!=0;
			p=p<<1;

		}
		bool isstart=false;
		for (int i = 31; i >=0; i--)
		{
			if(!isstart&&!Indexs[i])
				continue;
			if(Indexs[i]&&!isstart)
			{	
				isstart=true;
			}
			if(isstart)
			{
				Indexs[i]=!Indexs[i];
			}
			
		}
		int result=0;
		for (int i = 31; i >=0; i--)
		{
			result=result<<1;
			if(Indexs[i])
				result=result+1;
		}
		return result;
    }
 /*   ///500. Keyboard Row
	Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.*/
	
	//bool IsInARow(string name)
	//{

	//}
	 vector<string> findWords(vector<string>& words) {
		 vector<string> result ;
		 map<char,int>  my_Map;
		 my_Map.insert(pair<char,int>('q',0)); 
		 my_Map.insert(pair<char,int>('w',0));
		 my_Map.insert(pair<char,int>('e',0));
		 my_Map.insert(pair<char,int>('r',0));
		 my_Map.insert(pair<char,int>('t',0));
		 my_Map.insert(pair<char,int>('y',0));
	     my_Map.insert(pair<char,int>('e',0));
	     my_Map.insert(pair<char,int>('e',0));
	     my_Map.insert(pair<char,int>('e',0));
	     my_Map.insert(pair<char,int>('e',0));
	     my_Map.insert(pair<char,int>('e',0));
    }
};

#endif