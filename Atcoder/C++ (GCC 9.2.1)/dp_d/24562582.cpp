#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<int>> dp(n + 1, vector<int> (3));
  for(int i = n - 1; i >= 0; --i) {
    dp[i][0] = a[i] + max(dp[i+1][1], dp[i+1][2]);
    dp[i][1] = b[i] + max(dp[i+1][0], dp[i+1][2]);
    dp[i][2] = c[i] + max(dp[i+1][0], dp[i+1][1]);
  }
  cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << '\n';
}