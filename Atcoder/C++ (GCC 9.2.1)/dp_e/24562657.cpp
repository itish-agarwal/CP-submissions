#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1e5 + 7;

using ll = long long;
const ll INF = 2e17 + 9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W;
  cin >> n >> W;
  vector<int> w(n), v(n);
  for(int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
  }
  vector<ll> dp(MAX_N, INF);
  dp[0] = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = MAX_N; j >= v[i]; --j) {
      dp[j] = min(dp[j], w[i] + dp[j - v[i]]);
    }
  }
  ll ans = 0;
  for(int i = 0; i < MAX_N; ++i) {
    if(dp[i] <= W) {
      ans = max(ans, (ll)i);
    }
  }
  cout << ans << '\n';
}