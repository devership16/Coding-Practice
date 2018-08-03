#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
using namespace std;
void moveZeroes(vector<int>& nums){
  int count = 0;
  int n = nums.size();
  for(int i=0;i<n;i++){
    if(nums[i]!=0){
      nums[count++]=nums[i];
    }
  }
  while(count<n){
    nums[count++]=0;
  }
}
int main(){
  vector<int> nums = {0,1,0,3,12};
  moveZeroes(nums);
  for(int i: nums){
    cout<<i<<endl;
  }
  return 0;
}
