#pragma once
#include<set>
#include<vector>
using namespace std;

 // Definition for an interval.
  struct Interval {
     int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
class SummaryRanges {
public:
    /** Initialize your data structure here. */
	vector<Interval> result;
    SummaryRanges() {
		result.clear();
    }
    
    void addNum(int val) {
		bool relult=false;
		for (vector<Interval>::iterator p = result.begin(); p != result.end(); p++)
		{
			if(!((*p).start<=val&&(*p).end>=val))
			{
				if((*p).start=val+1)
				{
					(*p).start=val;
					relult=true;
				}
				else if((*p).end=val+1)
				{

				}
			}
		}
    }
    
    vector<Interval> getIntervals() {
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */