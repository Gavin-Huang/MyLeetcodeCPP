#pragma once
#include<vector>
#include <algorithm>
#include<map>
using namespace std;
class NO220
{
public:
	NO220(void);
	~NO220(void);
	 
	 bool FindByHalf(vector<int>& nums)
	 {

	 }
 	    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
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
};

