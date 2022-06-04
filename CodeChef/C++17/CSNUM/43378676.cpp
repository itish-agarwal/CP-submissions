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
    int ss = 0;
    for(char ch : s) {
      ss += ch-'0';
    }
    int n = s.size();
    if(ss % n) {
      cout << "Try Again\n";
    } else {
      cout << "Good work\n";
    }
  }
}
