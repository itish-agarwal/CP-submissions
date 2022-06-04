#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for(char& c : s) {
    if(c=='6') {
      c = '9';
    } else if(c == '9') {
      c = '6';
    }
  }
  reverse(s.begin(), s.end());
  cout<<s<<endl;
}