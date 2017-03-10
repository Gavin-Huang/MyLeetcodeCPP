#ifndef _Solution220
#define _Solution220
#include<vector>
#include   <map> 
#include <ctype.h>
#include<iostream>
using namespace std;
class Solution220 {
public:
	Solution220()
	{}
   /*   ///500. Keyboard Row
	Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.*/
	
	//bool IsInARow(string name)
	//{

	//}
	 vector<string> findWords(vector<string>& words) {
		 vector<string> result;
		 int numbers[3];
		 map<char,int>  my_Map;
		 my_Map.insert(pair<char,int>('q',0)); 
		 my_Map.insert(pair<char,int>('w',0));
		 my_Map.insert(pair<char,int>('e',0));
		 my_Map.insert(pair<char,int>('r',0));
		 my_Map.insert(pair<char,int>('t',0));
		 my_Map.insert(pair<char,int>('y',0));
	     my_Map.insert(pair<char,int>('u',0));
	     my_Map.insert(pair<char,int>('i',0));
	     my_Map.insert(pair<char,int>('o',0));
	     my_Map.insert(pair<char,int>('p',0));

	     my_Map.insert(pair<char,int>('a',1));
		 my_Map.insert(pair<char,int>('s',1));
		 my_Map.insert(pair<char,int>('d',1));
		 my_Map.insert(pair<char,int>('f',1));
		 my_Map.insert(pair<char,int>('g',1));
		 my_Map.insert(pair<char,int>('g',1));
		 my_Map.insert(pair<char,int>('h',1));
		 my_Map.insert(pair<char,int>('j',1));

		  my_Map.insert(pair<char,int>('z',2));
		  my_Map.insert(pair<char,int>('x',2));
		  my_Map.insert(pair<char,int>('c',2));
	      my_Map.insert(pair<char,int>('v',2));
		  my_Map.insert(pair<char,int>('b',2));
		  my_Map.insert(pair<char,int>('n',2));
		  my_Map.insert(pair<char,int>('m',2));
		  int begain=0;
		  for (int i = 0; i <words.size() ; i++)
		  {
			  if(IsInOneRow(my_Map,words[i]))
			  {
				  result.insert(result.end(),words[i]);
			  }
		  }
		  return result;
    }
	 bool IsInOneRow(map<char,int> &mo,string name)
	 {
		 int indexs=-1;
		 int i =0;
		 cout<<"begain: "<<endl;
		 while (name[i++]!='\0')
		 {   
	       char g=name[i];
		   if(isupper(g)) 
			 g=tolower(g);
		   cout<<g<<" ";
		   if(indexs==-1)
			   indexs=mo.at(g);
		   else
		   {
			   if(indexs!=mo.at(g))
				   return false;
		   }
		   cout<<mo.at(g)<<" ";
		   i++;
		 }
		 return true;
		 
	 }


    //217. Contains Duplicate
	//Given an array of integers, find if the array contains any duplicates. 
	//Your function should return true if any value appears at least twice in the array,
	//and it should return false if every element is distinct.
    //Subscribe to see which companies asked this question.
	bool containsDuplicate(vector<int>& nums)
	{
        map<int,int>  my_Map;
		for (int i = 0; i < nums.size(); i++)
		{
			if(my_Map.find( nums[i] ) != my_Map.end())
			{
				return true;
			}
			else
			{
				my_Map.insert(pair<int,int>(nums[i],0));
			}
		}
		return false;
    }
	//219. Contains Duplicate II
	//Given an array of integers and an integer k,
	//find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
    //Subscribe to see which companies asked this question.
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
        map<int,int>  my_Map;
		for (int i = 0; i < nums.size(); i++)
		{
			if(my_Map.find( nums[i] ) != my_Map.end())
			{
				if(i-my_Map[nums[i]]<=k)
					return true;
				else
				{
					 my_Map[nums[i]]=i;
				}
			}
			else
			{
				my_Map.insert(pair<int,int>(nums[i],i));
			}
		}
		return false;
    }
	    //220. Contains Duplicate III
	    /*Given an array of integers,
		find out whether there are two distinct indices i and j in the array 
		such that the absolute difference between nums[i] and nums[j] is at most t 
		and the absolute difference between i and j is at most k.
        Subscribe to see which companies asked this question.*/

	    bool containsNearbyAlmostDuplicate_TimeExceeded(vector<int>& nums, int k, int t) 
		{
		map<long int,int>  my_Map;
		long int Long_t =t;
		bool IsInthere=false;
		for (int i = 0; i < nums.size(); i++)
		{
			long int Num=nums[i];
			IsInthere=false;
			//for (int p = -t; p <=t; p++)
			//{
			//	if(my_Map.find(Num+p)!=my_Map.end())
			//	{
			//		if(i-my_Map[Num+p]<=k) return true;
			//	}
			//}
	    	for (std::map<long int,int>::iterator it=my_Map.begin(); it!=my_Map.end(); ++it)
			{
				if(abs(it->first-Num)<=Long_t&&i-it->second<=k)
				{
					return true;
				}
			}
			if(my_Map.find(Num)!=my_Map.end())
			{
				my_Map[Num]=i;
			}
			else
			{
			my_Map.insert(pair<long int,int>(nums[i],i));
			}
		}
		return false;
        }


	    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
		{
	    vector<vector<long int>> my_Map;
		//map<long int,int>  my_Map;
		long int Long_t =t;
        
		for (int i = 0; i < nums.size(); i++)
		{
			long int Num=nums[i];
			//for (int p = -t; p <=t; p++)
			//{
			//	if(my_Map.find(Num+p)!=my_Map.end())
			//	{
			//		if(i-my_Map[Num+p]<=k) return true;
			//	}
			//}
			int Size=my_Map.size();
			std::vector<vector<long int>>::iterator it;
			std::vector<vector<long int>>::iterator begin=my_Map.begin();
			std::vector<vector<long int>>::iterator end=my_Map.end();
			int isover=false;
			while (!isover&&!begin->empty()&&!end->empty())
			{   
				it=begin;
				if(abs((*it)[0]-Num)<=Long_t&&i-(*it)[1]<=k)
				{
					return true;
				}
				it=end;
				if(abs((*it)[0]-Num)<=Long_t&&i-(*it)[1]<=k)
				{
					return true;
				}
				if(Num<(*(begin+Size/2))[0])
				{
					end=begin+Size/2;
					Size=Size/2;
				}
				else
				{
					begin=begin+Size/2;
					Size=Size/2;
				}
				if(Size==1)
				{
					isover=true;
				}
			}
	    /*	for (it=my_Map.begin(); it!=my_Map.end(); )
			{   
				if(abs(it->first-Num)<=Long_t&&i-it->second<=k)
				{
					return true;
				}
				
			}*/
			if(!it->empty())
			{
			if((*it)[0]==Num)
			{
				(*it)[1]=i;
			}
			else
			{   vector<long int> temp;
			temp.insert(temp.end(),Num);
			temp.insert(temp.end(),i);
				my_Map.insert(it,temp);
			}
			}
		}
		return false;
        }
		};
#endif