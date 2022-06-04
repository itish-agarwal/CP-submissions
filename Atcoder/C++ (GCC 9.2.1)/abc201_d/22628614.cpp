#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  char grid[n][m];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int dp[n][m];

  for(int i = n - 1; i >= 0; i--) {
    for(int j = m - 1; j >= 0; j--) {
      if(i==n-1 && j==m-1) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = -2e9;
        if(i + 1 < n) {
          dp[i][j] = max(dp[i][j], (grid[i + 1][j] == '+' ? 1 : -1) - dp[i + 1][j]);
        }
        if(j + 1 < m) {
          dp[i][j] = max(dp[i][j], (grid[i][j + 1] == '+' ? 1 : -1) - dp[i][j + 1]);
        }
      }
    }
  }

  if(dp[0][0] > 0) {
    cout << "Takahashi\n";
  } else if(dp[0][0] < 0) {
    cout << "Aoki\n";
  } else {
    cout << "Draw\n";
  }
  return 0;
}