#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n+1), dp(n+1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    map<int, int> lst;
    for(int i = 1; i <= n; i++) {
      dp[i] = dp[i-1] + 1;
      if(lst[a[i]] > 0) {
        dp[i] = min(dp[i], i - lst[a[i]] - 1 + dp[lst[a[i]]-1]);
      } 
      lst[a[i]] = i;
    }
    cout << dp[n] << '\n';
  }
  return 0; 
} 
