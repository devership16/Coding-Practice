/*

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval{
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

vector<Interval> merge(vector<Interval>& intervals){
  sort(intervals.begin(),intervals.end(),[](Interval const& a, Interval const& b){return a.start<b.start;});
  vector<Interval> mergedRes;

  for(Interval interval: intervals){
    if (mergedRes.empty() || mergedRes.back().end < interval.start){
      mergedRes.push_back(interval);
    }
    else{
      mergedRes.back().end = max(mergedRes.back().end,interval.end);
    }
  }
  return mergedRes;
}
int main(){

  vector<Interval> intervals = {{1,3},{8,10},{15,18},{2,6}};
  vector<Interval> result = merge(intervals);
  for (Interval interval: result){
    cout<<interval.start<<" "<<interval.end<<endl;
  }

  return 0;
}
