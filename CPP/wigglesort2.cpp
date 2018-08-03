#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/* Problem definition
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].

*/
  void wiggleSort (vector<int>& nums ){
    sort(nums.begin(),nums.end());
    vector<int> temp = nums;
    int n = nums.size();
    int mid = (n-1)/2;
    int end = (n-1);
    for(int i=0;i<=n-1;i++){
      if(i%2==0){
        nums[i]=temp[mid--];
      }
      else{
        nums[i]=temp[end--];
      }
    }

  }

int main(){
  vector<int> nums = {1, 5, 1, 1, 6, 4};
  wiggleSort(nums);
  for(int i: nums){
    cout<<i<<"  ";
  }
  cout<<"\n";
  return 0;
}
