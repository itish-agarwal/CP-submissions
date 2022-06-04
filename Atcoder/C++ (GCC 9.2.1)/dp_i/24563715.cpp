#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<double> p(n + 1);
  for(int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  vector<vector<double>> dp(n + 1, vector<double> (n + 1));
  dp[1][1] = p[1];
  dp[1][0] = 1.0 - p[1];
  for(int i = 2; i <= n; ++i) {
    for(int j = 0; j <= i; ++j) {
      dp[i][j] = (1.0 - p[i]) * dp[i-1][j] + p[i] * (j >= 1 ? dp[i-1][j-1] : 0);
    }
  }
  double ans = 0;
  for(int j = n/2 + 1; j <= n; ++j) {
    ans += dp[n][j];
  }
  printf("%.12lf\n", ans);
}