#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generateMatrix(int n){
  vector<vector<int>> res(n, vector<int>(n,0));
  int top = 0;
  int left = 0;
  int right = n;
  int bottom = n;
  for(int i = 1; i <= n*n;) {
      for(int c = left; c < right; ++c) {
          res[top][c] = i++;
      }
      ++top;
      for(int r = top; r < bottom; ++r) {
          res[r][right-1] = i++;
      }
      if(i > n*n) break;
      --right;
      for(int c = right; c > left; --c) {
          res[bottom-1][c-1] = i++;
      }
      --bottom;
      for(int r = bottom; r > top; --r) {
          res[r-1][left] = i++;
      }
      ++left;
  }
  return res;
}
int main(){
  int n = 1;
  vector<vector<int>> res = generateMatrix(n);
  for(vector<int> i: res){
    for(int j: i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}
