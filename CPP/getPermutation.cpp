#include<iostream>
#include<vector>
#include<string>
using namespace std;
string getPermutation(int n, int k){
  string res="";
  vector<int> num;
  for(int i =1;i<=n;i++){
    num.push_back(i);
  }
  for(int i = 1;i<=k-1;i++){
    next_permutation(num.begin(),num.end());
  }
  for(int i: num){
    res+=to_string(i);
  }
  return res;
}
int main(){
  int n = 3, k = 3;
  cout<<getPermutation(n,k)<<endl;
  return 0;
}
