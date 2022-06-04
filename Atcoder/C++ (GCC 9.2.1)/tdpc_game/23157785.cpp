#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, s = 0;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
    s += b[i];
  }
  vector<vector<int>> dp(n + 1, vector<int> (m + 1));
  for(int i = n; i >= 0; i--) {
    for(int j = m; j >= 0; j--) {
      if(i == n) {
        for(int k = j; k < m; k++) {
          if((k - j) % 2) {
            dp[i][j] -= b[k];
          } else {
            dp[i][j] += b[k];
          }
        }
        continue;
      }
      if(j == m) {
        for(int k = i; k < n; k++) {
          if((k - i) % 2) {
            dp[i][j] -= a[k];
          } else {
            dp[i][j] += a[k];
          }
        }
        continue;
      }
      dp[i][j] = max(a[i] - dp[i + 1][j], b[j] - dp[i][j + 1]);
    }
  }
  cout << (dp[0][0] + s)/2 << '\n';
}