#include<iostream>
#include<vector>
using namespace std;
void gameOfLife(vector<vector<int>>& board){

  int n = board.size();
  int m =  board[0].size();
  if (m<=0 || n<=0){
    return;
  }
  int xDir[] = {-1 , -1, -1, 0, 1, 1,  1,  0};
  int yDir[] = {-1 ,  0,  1, 1, 1 ,0, -1, -1};

  for(int i=0;i<=n-1;i++){
    for(int j=0;j<=m-1;j++){
      cout << board[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      int neighbourCount = 0;

      for(int k =0 ;k<8;k++){
        int x = i+xDir[k], y = j+yDir[k];
        if (x >=0 && x < n && y>=0 && y<m &&(board[x][y] == 1 || board[x][y]==2)){
          neighbourCount++;
        }
      }
      if(board[i][j] && (neighbourCount<2 || neighbourCount > 3)){
          board[i][j]=2;
        }
      else if(!board[i][j] && neighbourCount==3){
          board[i][j]=3;
        }
      cout << neighbourCount << " ";
    }
    cout<< endl;
  }
  cout<< endl;
  // [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

  for(int i=0;i<=n-1;i++){
    for(int j=0;j<=m-1;j++){
      cout << board[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  for(int i=0;i<=n-1;i++){
    for(int j=0;j<=m-1;j++){
      board[i][j]%=2;
    }
  }
}
int main(){
  vector<vector<int>> board = {
                                {0,1,0},
                                {0,0,1},
                                {1,1,1},
                                {0,0,0}
                              };
  gameOfLife(board);
  for(int i = 0;i<=board.size()-1;i++){
    for(int j=0;j<=board[i].size()-1;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
