#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums){
  int n = nums.size();
  if (n==0){
    return 0;
  }
  int res = n*(n+1)/2;
  for(int i = 0; i<=n-1;i++){
    res-=nums[i];
  }
  return res;
}
int main(){
  vector<int> nums = {0,1};
  cout<<missingNumber(nums)<<endl;
}
