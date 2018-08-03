#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix){
  int m = matrix.size();
  int n = matrix[0].size();
  vector<int> res;
  int r = 0,c=0;
  while(r<m && c<n ){
  for(int i = c;i<n;i++){
    res.push_back(matrix[r][i]);
  }
  r+=1;
  for(int i = r;i<m;i++){
    res.push_back(matrix[i][n-1]);
  }
  n-=1;
  if(r<m){
    for(int i=n-1;i>=c;i--){
      res.push_back(matrix[m-1][i]);
    }
    m-=1;
  }
  if(c<n){
    for(int i = m-1;i>=r;i--){
      res.push_back(matrix[i][c]);
    }
    c+=1;
  }
}
  return res;
}
int main(){
  vector<vector<int>> matrix = {
                                 { 1, 2, 3 },
                                 { 4, 5, 6 },
                                 { 7, 8, 9 }
                               };
  vector<int> res = spiralOrder(matrix);
  for(int i: res){
    cout<<i<<" ";
  }
  cout<<endl;
}
