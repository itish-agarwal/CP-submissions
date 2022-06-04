#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  bool c_x = 0;
  for(char ch : s) {
    if(ch == 'x') {
      c_x = 1;
      break;
    }
  }
  if(c_x) {
    cout << "YES\n";
  } else {
    if(s == t) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
