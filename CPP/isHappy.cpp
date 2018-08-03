#include<iostream>
using namespace std;
bool isHappy(int n){
  int count  =40;
  while(count--){
    int sum =0;
    while(n!=0){
      int digit = n%10;
      sum+= digit*digit;
      n/=10;
    }
    n = sum;
    if(n==1){
      return true;
    }
  }
  return false;
}
int main(){
  int n = 19;
  cout<<isHappy(n)<<endl;
  return 0
}
