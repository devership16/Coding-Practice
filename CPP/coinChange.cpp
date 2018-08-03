#include<iostream>
#include<vector>
using namespace std;
int coinChange(vector<int>& coins, int amount){
  int max_val = amount + 1;
  vector<int> cost(amount + 1, max_val);
  cost[0] = 0;
  for (int i = 1; i <= amount; i++) {
    for (int j = 0; j < coins.size(); j++) {
      if (coins[j] <= i) {
        cost[i] = min(cost[i], cost[i - coins[j]] + 1);
      }
    }
  }
  return cost[amount] > amount ? -1 : cost[amount];
}
int main(){
  vector<int> coins= {1, 2, 5};
  int amount = 11;
  int noCoin = coinChange(coins, amount);
  cout<<noCoin<<endl;
  return 0;
}
