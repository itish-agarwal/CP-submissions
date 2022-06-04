#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int n = s.size();
    int i = 0, j = n - 1;
    while(i < j) {
      if(s[i] != s[j]) {
        break;
      }
      i++;
      j--;
    }
    if(i >= j) {
      cout << s << '\n';
    } else {
      string t = s.substr(0, i);
      string m = t;
      reverse(m.begin(), m.end());
      char ch = min(s[i], s[j]);
      t += ch;
      cout <<t + m << '\n';
    }
  }
}
