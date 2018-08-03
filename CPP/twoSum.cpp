#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res;
        for(int  i=0; i<nums.size();i++){
            if (m.find(nums[i]) != m.end()){
                res.push_back(m[nums[i]]);
                res.push_back(i);
                return res;
            }
            else{
                m.insert(pair <int,int>(target-nums[i],i));
            }
        }


    }
int main()
{
  vector<int> nums = {3,2,4};
  int target = 6;
  vector<int> res = twoSum(nums,target);
  for (int i: res)
    cout<< i << endl;
  return 0;
}
