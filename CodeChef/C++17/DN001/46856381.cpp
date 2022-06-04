#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a(n), pref(n);
  for(int i = 0; i < n; i++) {
    a[i] = 26 - (s[i] - 'a');
    if(i>0) {
      pref[i] = pref[i-1] + a[i];
    } else {
      pref[i] = a[i];
    }
  }
  vector<vector<int>> dp(n, vector<int> (n));
  for(int l = n - 1; l >= 0; l--) {
    for(int r = l; r < n; r++) {
      if(l == r) {
        dp[l][r] = a[l];
        continue;
      }
      if(r == l + 1) {
        dp[l][r] = max(a[l], a[r]);
        continue;
      }
      int sum = pref[r] - (l>0 ? pref[l-1] : 0);
      dp[l][r] = max(sum - dp[l+1][r],sum - dp[l][r-1]);
    }
  }
  cout << dp[0][n-1] << '\n';
}