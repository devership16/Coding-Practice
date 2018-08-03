#include<iostream>
#include<vector>
#include<string>
#include<numeric>
using namespace std;
int calculate(string s) {
        int res = 0, temp = 0;
        char sign = '+';
        //for(int i = s.find_first_not_of(' '); i < s.size(); i = s.find_first_not_of(' ', i)) {
        for(int i = 0;i<s.size();){
          if(s[i]==' '){
            i++;
            continue;
          }
            if(isdigit(s[i])) {
                int digit = s[i] - '0';
                while(i++ < s.size() && isdigit(s[i]))
                    digit = digit*10 + (s[i] - '0');
                switch(sign) {
                    case '+' : temp += digit; break;
                    case '-' : temp -= digit; break;
                    case '*' : temp *= digit; break;
                    case '/' : temp /= digit; break;
                }
            }
            else {
                if(s[i] == '+' || s[i] == '-') {
                    res += temp;
                    temp = 0;
                }
                sign = s[i++];
            }
        }
        return res + temp;
    }
int main(){
  string s = " 3/2";
  cout<< calculate(s)<<endl;
  return 0;
}
