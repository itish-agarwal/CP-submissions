#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W;
  cin >> n >> W;
  vector<int> w(n), v(n);
  for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
  vector<vector<long long>> dp(n, vector<long long> (W + 1, 0));
  for(int j = 0; j <= W; j++) {
    dp[n - 1][j] = (j >= w[n - 1] ? v[n - 1] : 0);
  }
  for(int i = n - 2; i >= 0; --i) {
    for(int j = 0; j <= W; j++) {      
      dp[i][j] = dp[i + 1][j];
      if(j >= w[i]) {
        dp[i][j] = max(dp[i][j], (long long)v[i] + dp[i + 1][j - w[i]]);
      }      
    }
  }
  cout << dp[0][W] << '\n';  
  return 0;
}
