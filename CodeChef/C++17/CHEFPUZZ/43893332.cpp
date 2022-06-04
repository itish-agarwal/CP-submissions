#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long
const int INF = 2e18 + 777; 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s, t;
    cin >> s >> t;
    int k;
    cin >> k;
    int s0 = 0, s1 = 0;
    for(char ch : s ) s0 += ch-'a';
    for(char ch : t) s1 += ch-'a';
    if(s0==s1) {
      bool ok = 1;
      for(int i = 0; i < (int)s.size(); ++i) {
        if(abs(s[i]-t[i]) > k) {
          ok = 0;
          cout << "LOSE\n";
          break;
        }
      }
      if(ok) cout << "WIN\n";
    } else {
      cout << "LOSE\n";
    }
  }
}
