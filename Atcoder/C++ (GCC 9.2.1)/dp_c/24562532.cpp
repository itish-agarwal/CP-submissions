#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W;
  cin >> n >> W;
  vector<int> w(n), v(n);
  for(int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
  }
  vector<ll> dp(W + 1);
  for(int i = 0; i < n; ++i) {
    for(int j = W; j >= w[i]; --j) {
      dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
    }
  }
  ll ans = 0;
  for(int j = 0; j <= W; ++j) {
    ans = max(ans, dp[j]);
  }
  cout << ans << '\n';
}