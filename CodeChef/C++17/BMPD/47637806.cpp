#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    int x = N - N % 10;
    int ans = min({x/10 * X, x/5 * Y, x * Z});
    N %= 10;

    const int INF = 2e18 + 7;

    vector<int> dp(N + 1, INF);

    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
      dp[i] = Z + dp[i - 1];
      if(i >= 5) 
        dp[i] = min(dp[i], Y + dp[i - 5]);
      if(i >= 10)
        dp[i] = min(dp[i], X + dp[i - 10]);
    }
    cout << ans + dp[N] << '\n';
  }
}