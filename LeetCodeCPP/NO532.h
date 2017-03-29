#pragma once
#include<stdio.h>
#include<math.h>
#include <climits>
#include<vector>
using namespace std;
//Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
//
//Example 1:
//Input: [3, 1, 4, 1, 5], k = 2
//Output: 2
//Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
//Although we have two 1s in the input, we should only return the number of unique pairs.
//Example 2:
//Input:[1, 2, 3, 4, 5], k = 1
//Output: 4
//Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
//Example 3:
//Input: [1, 3, 1, 5, 4], k = 0
//Output: 1
//Explanation: There is one 0-diff pair in the array, (1, 1).
//Note:
class Solution532 {
public:
      int findPairs(vector<int>& nums, int k) {
		  int count=0;
		//  vector<int> added;
		  vector<vector<int>> added;
		  if(nums.size()>2)
		  {
		  for (int i = 0; i < nums.size()-1; i++)
		  {
			   for (int j = i+1; j < nums.size(); j++)
		  {
			  if(abs(nums[i]-nums[j])==k)
			  {  bool result=false;
			  for (int p = 0; p < added.size(); p++)
			  {
				  if((added[p][0]==nums[i]&&added[p][1]==nums[j])
					  ||(added[p][0]==nums[j]&&added[p][1]==nums[i]))
				  {
					  result=true;
					  break;
				  }
			  }
			  if(!result)
				 { 
					 count++;
					 vector<int> newOne;newOne.push_back(nums[i]);newOne.push_back(nums[j]);
					 added.push_back(newOne);
			  }
			  }
		  }
		  }
		  }
		  return count;
    }
    
};