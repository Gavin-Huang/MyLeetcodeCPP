#pragma once 
#include<vector>
#include<iostream>
using namespace std;
class NO448 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> all;
		for(int i=0;i<nums.size();i++)
        {
			if(nums[i]==i+1)
				continue;
			int temp=nums[i];
			while(nums[temp-1]!=temp)
			{
				nums[i]=nums[temp-1];
				nums[temp-1]=temp;
				temp=nums[i];
			}
        }
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i]!=i+1)
				all.insert(all.end(),i+1);
		}
        return all;
    }
};