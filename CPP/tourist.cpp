#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  long long T,N,K,V,caseNum=1;
  string attrName;
  vector<int> attr;
  vector<string> attrNames;
  cin>>T;
  while(T--){
    attr.clear();
    attrNames.clear();
    cin>>N>>K>>V;
    //cout<<N<<" "<<K<<" "<<V<<endl;
    for(int i=0;i<N;i++){
      cin>>attrName;
      attrNames.push_back(attrName);
    }
    long long startIndex = K*(V-1);
    for(int i=0;i<K;i++){
      attr.push_back((i+startIndex)%N);
    }
    sort(attr.begin(),attr.end());
    cout<<"Case #"<<caseNum<<":";
    for(int i=0;i<K;i++){
      cout<<" "<<attrNames[attr[i]];
    }
    cout<<"\n";
    caseNum+=1;
  }
  return 0;
}
