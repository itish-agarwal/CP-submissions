#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int> (m + 1));
  for(int i = n - 1; i >= 0; --i) {
    for(int j = m - 1; j >= 0; --j) {
      if(s[i] == t[j]) {
        dp[i][j] = 1 + dp[i + 1][j + 1];
      } else {
        dp[i][j] = max({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
      }
    }
  }
  cout << dp[0][0] << '\n';
}