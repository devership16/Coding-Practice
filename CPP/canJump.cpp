/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*/

#include<iostream>
#include<vector>
using namespace std;
bool canJumpUtilR(int pos,const vector<int>& nums){
  if(pos == nums.size() - 1){
    return true;
  }
  int maxJump = (nums[pos]+pos < nums.size()-1)?nums[pos]+pos:nums.size()-1;
  for(int i = pos+1;i<=maxJump;i++){
    if(canJumpUtilR(i,nums)){
      return true;
    }
  }
  return false;
}
bool canJumpR(const vector<int>& nums){
  return canJumpUtilR(0,nums);
}



bool canJumpUtilTD(int pos,  int *posDetail, const vector<int>& nums){
  if (posDetail[pos]!=0){
    return (posDetail[pos]==1)?true:false;
  }
  int maxJump = (nums[pos]+pos < nums.size()-1)?nums[pos]+pos:nums.size()-1;
  for(int i = pos+1;i<=maxJump;i++){
    if(canJumpUtilTD(i,posDetail,nums)){
      posDetail[i]=1;
      return true;
    }
  }
  posDetail[pos]=0;
  return false;

}
bool canJumpTD(const std::vector<int>& nums){
  int posDetail[nums.size()];
  memset(posDetail,0,sizeof(posDetail));
  posDetail[nums.size()-1] = 1;
  return canJumpUtilTD(0,posDetail,nums);

}

bool canJump(const std::vector<int> nums){
  int n = nums.size()-1;
  for(int i = n;i>=0;i--){
    if(i+nums[i]>=n){
      n = i;
    }
  }
  return n == 0;
}

int main(){
  vector<int> nums1 = {2,3,1,1,4};
  vector<int> nums2 = {3,2,1,0,4};
  cout<<canJump(nums1)<<endl; //true
  cout<<canJump(nums2)<<endl; //false
  return 0;
}
