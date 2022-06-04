#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long
const int inf = 2e18 + 555;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int S = 0;
    for(auto& it : a) {
      cin >> it;
      S += it;
    }
    if(S % 2) {
      cout << "Not Impressed\n";
    } else {
      vector<bool> dp(S + 1, 0);
      dp[0] = 1;
      for(int i = 1; i <= S; i++) {
        for(int x : a) {
          if(x == 1) {
            dp[i] = 1;
          }
          if(i-x>=0 && dp[i-x]) {
            dp[i] = 1;
          }
        }
      }
      if(dp[S/2]) {
        cout << "Impressed\n";
      } else {
        cout << "Not Impressed\n";
      }
    }
  }
  return 0;
}
