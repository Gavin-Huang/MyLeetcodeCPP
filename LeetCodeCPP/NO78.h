#pragma once
#include<vector>
using namespace std;
class NO78
{
public:
	NO78();
	~NO78();
//	Total Accepted: 147103
//Total Submissions: 387898
//Difficulty: Medium
//Contributors: Admin
//Given a set of distinct integers, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//If nums = [1,2,3], a solution is:
//
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]
//Subscribe to see which companies asked this question.
//
//Show Tags
//Show Similar Problems

	vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> reslut;
       //i for counts
	   //
	   vector<int> nullt;
	   reslut.push_back(nullt);
	   for (int i = 1; i < nums.size()+1; i++)
	   {   
		   auto tem =GetVector(nums,0,i);
		   for (int j = 0; j < tem.size(); j++)
		   {
			   reslut.push_back(tem[j]);
		   }
	   }
	   return reslut;
    }
	vector<vector<int>> GetVector(vector<int>& raw,int index,int count)
	{    vector<vector<int>> result;
	     if(count==0) return result;
		for (int i = index; i <= raw.size()-count; i++)
		{   if(index=1) 
		   int pl=0;
			auto tem=GetVector(raw,i+1,count-1);
			for (int j = 0; j < tem.size(); j++)
			{
				tem[j].insert(tem[j].begin(),raw[i]);
				result.push_back(tem[j]);
			}
			if(tem.size()==0)
			{
				vector<int> temp;
				temp.push_back(raw[i]);
				result.push_back(temp);
			}
		}
		return result;
	}
	void test()
	{   vector<int> nums;
     	nums.push_back(1);
		nums.push_back(2);
		nums.push_back(3);
		subsets(nums);
	}
private:

};

NO78::NO78()
{
}

NO78::~NO78()
{
}