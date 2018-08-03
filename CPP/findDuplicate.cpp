#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findDuplicate(vector<int>& nums){
  int slow = nums[0],fast=nums[0],temp=nums[0];
  do{
    slow = nums[slow];
    fast = nums[nums[fast]];
  }while(slow!=fast);
  while(slow!=temp){
    slow = nums[slow];
    temp = nums[temp];
  }

  return temp;
}

int main(){
  vector<int> nums = {1,3,4,2,2};
  int res = findDuplicate(nums);
  cout<<res<<endl;
  return 0;
}
