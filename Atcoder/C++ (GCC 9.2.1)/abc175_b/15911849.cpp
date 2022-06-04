#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  if(s[0]==s[1] && s[1]==s[2] && s[0]=='R') {
    cout << 3 << '\n';
  } else if(s[0]==s[1] && s[0]=='R') {
    cout << 2 << '\n';
  } else if(s[1]==s[2] && s[1]=='R') {
    cout << 2 << '\n';
  } else if(s[0]=='R' || s[1]=='R' || s[2]=='R') {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}
