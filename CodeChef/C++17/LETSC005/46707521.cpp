#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int> (m));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j] ^= 1;
    }
  }
  int ans = 0;
  vector<vector<int>> dp(n, vector<int> (m));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(i<1 || j<1) {
        dp[i][j] = a[i][j];
      } else {
        if(a[i][j]) {
          dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans*ans << '\n';
  return 0;
}