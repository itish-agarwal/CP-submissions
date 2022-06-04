#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char> (m));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int> (m));
  for(int i = n - 1; i >= 0; --i) {
    for(int j = m - 1; j >= 0; --j) {
      if(i == n - 1  && j == m - 1) {
        dp[i][j] = 1;
        continue;
      }
      if(grid[i][j] == '.') {
        if(i + 1 < n) {
          add_self(dp[i][j], dp[i + 1][j]);
        }
        if(j + 1 < m) {
          add_self(dp[i][j], dp[i][j + 1]);
        }
      }
    }
  }
  cout << dp[0][0] << '\n';
}