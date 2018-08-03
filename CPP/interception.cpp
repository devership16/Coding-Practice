#include<iostream>
using namespace std;

int main(){
  int t,caseNum =1;
  int n,temp;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<=n;i++){
      cin>>temp;
    }
    if(n%2==0){
      cout<<"Case #"<<caseNum<<": 0\n";
    }
    else{
      cout<<"Case #"<<caseNum<<": 1\n0.0\n";
    }
    caseNum+=1;
  }
  return 0;
}
