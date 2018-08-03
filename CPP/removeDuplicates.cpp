#include<iostream>
#include<vector>
#include<unordered_set>

int main(){
  std::vector<int> nums = {2, 4, 10, 20, 5, 2, 20, 4};
  std::unordered_set<int> uniqueNums;
  for(int i=0;i<nums.size();i++){
    uniqueNums.insert(nums[i]);
  }
  nums.assign(uniqueNums.begin(), uniqueNums.end());
  for(int num: nums){
    std::cout<<num<<" ";
  }
  return 0;
}
