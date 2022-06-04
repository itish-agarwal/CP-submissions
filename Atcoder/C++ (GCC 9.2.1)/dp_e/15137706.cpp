#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18 + 5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W, V = 0;
  cin >> n >> W;
  vector<int> w(n), v(n);  
  for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
  for(int i = 0; i < n; i++) V += v[i];
  vector<vector<ll>> dp(n + 1, vector<ll> (V + 1, inf));
  for(int i = 0; i <= n; i++) dp[i][0] = 0LL;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= V; j++) {
      if(j >= v[i - 1] && dp[i - 1][j - v[i - 1]] < inf) {
        dp[i][j] = min(dp[i - 1][j], (ll)w[i - 1] + dp[i - 1][j - v[i - 1]]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  ll ans = 0;
  for(int j = 1; j <= V; j++) {
    if(dp[n][j] <= W) ans = j;
  }
  cout << ans << '\n';
  return 0;
}
      
