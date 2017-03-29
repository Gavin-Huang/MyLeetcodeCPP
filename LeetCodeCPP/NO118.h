#pragma once
#include<stdio.h>
#include<math.h>
#include <climits>
#include<vector>

using namespace std;
class Solution118{  public :
//118. Pascal's Triangle
 vector<vector<int>> generate(int numRows)
 {
	    vector<vector<int>> result;
        for(int i=0;i<numRows;i++)
		{   vector<int> temp;
		     for(int j=0;j<i+1;j++)
			 {
				 temp.push_back(getNumber(result,i,j));
			 }
			 if(temp.size()>0)
			 result.push_back(temp);
		}
		return result;
    }
 int getNumber( vector<vector<int>> result,int i,int j)
 {
	 int Index=i-1;
	 if(Index<0)
	 {
		 return 1;
	 }
	 else
	 {   if(i==2&&j==1)
	 {
		 int p=0;
	 }
		 return (j-1>=0?result[Index][j-1]:0)+(j<result[Index].size()?result[Index][j]:0);
	 }
 }
 void test2()
{
Solution118 fg ;
fg.generate(6);

}
};