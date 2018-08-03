#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
int main(){
  int T, N, caseNum=1;
  vector<string> flowMap;
  cin>>T;
  long long modeVal = 1000000007;
  while(T--){
    string flowLine;
    bool inValid = false;
    long long res = 0;
    flowMap.clear();

    cin>>N;
    int count = N;

    for(int i=0;i<3;i++){
      cin>>flowLine;
      flowMap.push_back(flowLine);
    }

    if(N%2!=0){
      res = 0;
    }
    else{
      if(flowMap[0][0]=='#' || flowMap[2][N-1]=='#'){
        res = 0;
        inValid = true;
      }
      else{
        for(int i=0;i<=N-1;i++){
          if (flowMap[1][i]=='#'){
              res = 0;
              inValid = true;
              break;
          }
          if(flowMap[0][i]=='#' && flowMap[2][i]=='#'){
            res = 0;
            inValid = true;
            break;
          }
          if(flowMap[0][i]=='#'||flowMap[2][i]=='#'){
            count-=1;
          }
        }
      }
      if(count<0){
        inValid = true;
      }
      if(inValid==true){
        res = 0;
      }
      else{
        count = count/2;
        //cout<<count<<endl;
        double temp = pow(2,count-1);
        res = temp;
      }
    }
    res = res % modeVal;
    cout<<"Case #"<<caseNum<<": "<<res<<"\n";
    caseNum+=1;
  }
  return 0;
}
