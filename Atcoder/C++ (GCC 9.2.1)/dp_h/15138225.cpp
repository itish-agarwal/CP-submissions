#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int row, col;
  cin >> row >> col;
  vector<vector<int>> grid(row, vector<int> (col));
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      char x; cin >> x;
      if(x == '.') grid[i][j] = 1;
      else grid[i][j] = 0;
    }
  }
  vector<vector<int>> dp(row, vector<int> (col, 0));
  dp[row - 1][col - 1] = (grid[row - 1][col - 1] == 1);
  for(int i = row - 1; i >= 0; --i) {
    for(int j = col - 1; j >= 0; --j) {
      if(i==row - 1 && j==col - 1) continue;
      if(grid[i][j] == 0) {
        dp[i][j] = 0;
      } else {
        if(i + 1 < row) add(dp[i][j], dp[i + 1][j]);
        if(j + 1 < col) add(dp[i][j], dp[i][j + 1]);
      }
    }
  }
  cout << dp[0][0] << '\n';
  return 0;
}
