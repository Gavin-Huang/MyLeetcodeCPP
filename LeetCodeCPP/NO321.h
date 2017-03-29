#pragma once
#include<vector>
#include<map>
using namespace std;

struct MyStruct
{
	int i;int j;int count;

};
struct MyStructCompare
{
	bool operator()(const MyStruct &k1,const MyStruct &k2)const
	{
		if(k1.i!=k2.i)
			return k1.i<k2.i;
		if(k1.j!=k2.j)
			return k1.j<k2.j;
		/*if(k1.count!=k2.count)
			return k1.count<k2.count;*/
		return false;
	}
};
class NO321 {
public:
	map<MyStruct,vector<int>,MyStructCompare> Fasttemps;
	 vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		  Fasttemps.clear();
		  vector<int> gh;
		 gh= GetMaxBefore(nums1.size(),nums2.size(),k,nums1,nums2);
		 return gh;
    }
	vector<int> Find(int i,int j,int kc,vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> tems;
		if(i+j<kc||i<0||j<0||kc<=0) return tems;
		//bool result=false;
		MyStruct temp;
		temp.i=i;temp.j=j;temp.count=kc;
		auto gg=Fasttemps.find(temp);
		if(gg!=Fasttemps.end())
		{   
			//cloneVector(gg->second,tems);
			if(gg->second.size()==kc)
			{
				vector<int> temsp(gg->second);
			    return temsp;
			}
			else if(gg->second.size()<kc)
			{
				auto temVec=GetMaxBefore(i,j,kc,nums1,nums2);
				if(temVec.size()==kc)
				{
					gg->second=temVec;
				}
				else
				{
					return tems;
				}
			}
			else
			{
				return tems;
			}
			
		}
		
		auto temVec=GetMaxBefore(i,j,kc,nums1,nums2);
		temp.i=i;temp.j=j;temp.count=kc;
	    Fasttemps.insert(pair<MyStruct, vector<int>>(temp,temVec));
		vector<int> temsp(temVec);
	    return temsp;
	}
	//s1<s2 1
	//s1>s2 -1
	//s1==s2 0
	int compare(vector<int>& s1,vector<int>& s2)
	{  

		if(s1.size()*s2.size()>0)
		{
			if(s1[0]*s2[0]>0)
			{
				if(s1.size()<s2.size())
				{
					return 1;
				}
				else if(s1.size()==s2.size())
				{
					int i=0;
					while (i<s1.size()&&s1[i]==s2[i])
					{
						i++;
					}
					if(i==s1.size())
					{
						return 0;
					}
					if(s1[i]<s2[i])
					{
						return 1;
					}
					else if(s1[i]<s2[i])
					{
						return -1;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return -1;
				}
			}
			else
			{
				if(s1[0]==0&&s2[0]!=0)
					return 1;
				if(s1[0]!=0&&s2[0]==0)
					return -1;
				return 0;
			}

		}
		else
		{
			if(s1.size()==0&&s2.size()!=0&&s2[0]!=0)
			{
				return 1;
			}
			if(s1.size()!=0&&s1[0]!=0&&s2.size()==0)
			{
				return -1;
			}
			return 0;
		}
	}
	void cloneVector(vector<int>& source,vector<int>& result)
	{
		result.clear();
		for (int i = 0; i < source.size(); i++)
		{   int temp=source[i];
		result.push_back(temp);
		}
	}
	vector<int>  GetMaxBefore(int i,int j,int kc,vector<int>& nums1, vector<int>& nums2)
	 {


		 vector<int> temGH,oldv;
		long long  int temi=-1,temj=-1;
		 int fromWhich=-1;
		 if(i+j<kc||i<0||j<0||kc<=0) return temGH;

		 
		/* int N1Left=nums1.size()-i;
		 int N2Left=nums2.size()-j;*/
		 int min1=kc-j-1>0?kc-j-1:0;
		 int min2=kc-i-1>0?kc-i-1:0;
		 for(int I1=i-1;I1>=min1;I1--)
		 {   
		     auto newv= Find(I1,j,kc-1,nums1,nums2);
			 newv.push_back(nums1[I1]);
			 int resultd =compare(oldv,newv);
			 if(resultd==1||resultd==0)
			 {
				 temi=I1;temj=j;
			     oldv=newv;
				 fromWhich=0;
			 }
		
		 }
		 for (int I2 = j-1; I2 >=min2; I2--)
	     {  
			auto  newv= Find(i,I2,kc-1,nums1,nums2);
			newv.push_back(nums2[I2]);
		  int resultd= compare(oldv,newv);
			if(resultd==1)
			 {
				temi=i;temj=I2;
				oldv=newv;
				fromWhich=1;
			 }
			  else if(resultd==0)
			 {
				 if(fromWhich==0)
				 {
					 if((temi+temj)>i+I2)
					 {
					   temi=i;temj=I2;
				       oldv=newv;
				       fromWhich=1;
					 }
				 }
				 else
				 {
					   temi=i;temj=I2;
				       oldv=newv;
				       fromWhich=1;
				 }
			 }
	      }
	    vector<int> temsp(oldv);
	    return temsp;
		 cloneVector(oldv,temGH);
		 return temGH;
	
	 }
	void test()
	{
		int p1[]={8,0,4,4,1,7,3,6,5,9,3,6,6,0,2,5,1,7,7,7,8,7,1,4,4,5,4,8,7,6,2,2,9,4,7,5,6,2,2,8,4,6,0,4,7,8,9,1,7,0};
		int p2[]={6,9,8,1,1,5,7,3,1,3,3,4,9,2,8,0,6,9,3,3,7,8,3,4,2,4,7,4,5,7,7,2,5,6,3,6,7,0,3,5,3,2,8,1,6,6,1,0,8,4};
		vector<int> nums1,nums2;
		for (int i = 0; i < sizeof(p1)/4; i++)
		{
			nums1.push_back(p1[i]);
		}
		for (int i = 0; i < sizeof(p2)/4; i++)
		{
			nums2.push_back(p2[i]);
		}
		maxNumber(nums1,nums2,50);
	}
};