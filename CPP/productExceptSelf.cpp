#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums){
  int n = nums.size();
  vector<int> left(n);
  vector<int> right(n);
  vector<int> prod(n);
  left[0]=1;
  right[n-1]=1;
  for(int i=1;i<n;i++){
    left[i]=left[i-1]*nums[i-1];
  }
  for(int j=n-2;j>=0;j--){
    right[j]=right[j+1]*nums[j+1];
  }
  for(int  i=0;i<=n-1;i++){
    prod[i]=left[i]*right[i];
  }
  return prod;
}
int main(){
  vector<int> nums = {1,2,3,4};
  vector<int> res = productExceptSelf(nums);
  for(int i: res){
    cout<<i<<endl;
  }
  return 0;
}
