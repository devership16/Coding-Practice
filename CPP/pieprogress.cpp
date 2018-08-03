#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
  int T,N,M;
  cin>>T;
  int caseNum=1;
  while(caseNum<=T){
    cin>>N>>M;
    long long cost[300],ans=0;
    priority_queue<int> pq;
    for(int day=0;day<N;day++){

      for(int i=0;i<M;i++){
        cin>>cost[i];
      }
      sort(cost,cost+M);
      for(int i=1;i<=M;i++){
        pq.push(-(cost[i-1]+(2*i)-1));
      }
      ans-=pq.top();
      pq.pop();
    }
    cout<<"Case #"<<caseNum<<": "<<ans<<endl;
    caseNum+=1;
  }
  return 0;
}
