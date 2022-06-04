#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W;
  cin >> n >> W;
  vector<int> w(n), v(n);
  for(int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  vector<vector<int>> dp(n+1, vector<int> (W+1));
  for(int i = n-1; i >= 0; i--) {
    for(int j = 0; j <= W; j++) {
      //do not take
      dp[i][j] = dp[i+1][j];
      if(w[i] <= j) {
        dp[i][j] = max(dp[i][j], dp[i+1][j-w[i]] + v[i]);
      }
    }
  }
  cout << dp[0][W] << '\n';
  return 0;
}
