#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int countPrimes(int n){
  int *flag = new int[n+1];
        for(int i=2;i*i<=n;i++)
            if(flag[i]==0)
                for(int j=i*2;j<=n;j+=i)
                    flag[j]=1;

        int count=0;
        for(int i=2;i<n;i++)
            if(flag[i]==0)
                count++;

        return count;
}
int main(){
  int n = 10000;
  cout<<countPrimes(n)<<endl;
}
