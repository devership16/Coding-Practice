#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

bool isAnagram(string s, string t){
  int n = s.length();
  int m = t.length();
  bool res = true;
  if (n!=m){
    return false;
  }
  int charCount[26]={0};
  for(auto c: s){
    charCount[c-'a']++;
  }
  for(auto c: t){
    charCount[c-'a']--;
  }
  for(int i=0;i<=25;i++){
    if(charCount[i]!=0){
      res=false;
      break;
    }
  }
  return res;
}

int main(){
  string s = "anagram";
  string t = "naagram";
  cout<< isAnagram(s,t)<<endl;
}
