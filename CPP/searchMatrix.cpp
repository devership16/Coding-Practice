#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target){

  int m = matrix.size();
  int n = matrix[0].size();
  int i = 0,j =n-1;
  while(i<=m-1 && j>=0){
    if(matrix[i][j]==target){
      return true;
    }
    if(matrix[i][j]<target){
      i+=1;
    }
    else{
      j-=1;
    }
  }

  return false;
}
int main(){
  vector<vector<int>> matrix = {
                                {1,   4,  7, 11, 15},
                                {2,   5,  8, 12, 19},
                                {3,   6,  9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}
                                };
  matrix ={{1,1}};
  int target = 20;
  cout<<searchMatrix(matrix,target)<<endl;
  return 0;
}
