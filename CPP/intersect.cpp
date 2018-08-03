#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;
        unordered_map<int,int> m1;
        for(int i: nums1){
          m1[i]++;
        }
        for(int i: nums2){
          if(m1[i]>0){
            res.push_back(i);
            m1[i]--;
          }
        }
        return res;

  }
int main(){
  vector<int> num1 = {1,2,2,1}, num2 = {2,2},res;
  res = intersect(num1,num2);
  for(int i: res){
    cout<<i<<endl;
  }
  return 0;
}
