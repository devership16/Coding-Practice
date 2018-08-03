#include<iostream>
#include<vector>
using namespace std;
int numSquares(int n){
  vector<int> dp(n+1);
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;
  dp[3]=3;
  for(int i=4;i<=n;i++){
    dp[i]=i;
    for(int j=1;j<=i;j++){
      int count = j*j;
      if(count>i){
        break;
      }
      else{
        dp[i]=min(dp[i],1+dp[i-count]);
      }
    }
  }
  return dp[n];
}
int main(){
  cout<<numSquares(8829)<<endl;

  return 0;
}
