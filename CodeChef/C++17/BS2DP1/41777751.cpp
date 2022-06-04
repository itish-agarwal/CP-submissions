#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 2e18 + 55;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  ll answer = -inf;
  vector<vector<ll>> dp(n + 1, vector<ll> (k + 1, 0));
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for(int j = 0; j <= k; j++) {
      dp[i][j] = x + max(0LL, dp[i-1][j]);
      if(j) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] - x);
      }
      answer = max(answer, dp[i][j]);
    }
  }
  cout << answer << '\n';
  return 0;
}
