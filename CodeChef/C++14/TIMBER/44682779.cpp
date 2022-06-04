#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int row, col;
  cin >> row >> col;
  vector<vector<int>> g(row + 2, vector<int> (col + 2));
  for(int i = 1; i <= row; ++i) {
    for(int j = 1; j <= col; ++j) {
      cin >> g[i][j];
    }
  }  
  for(int i = 1; i <= row; ++i) {
    for(int j = 1; j <= col; ++j) {
      g[i][j] += g[i][j-1];
    }
  }
  for(int j = 1; j <= col; ++j) {
    for(int i = 1; i <= row; ++i) {
      g[i][j] += g[i-1][j];
    }
  }
  int qq;
  cin >> qq;
  while(qq--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    //top left -> x1, y1
    //bottom right -> x2, y2;
    int ans = g[x2][y2];
    ans -= g[x1-1][y2];
    ans -= g[x2][y1-1];
    ans += g[x1-1][y1-1];
    cout << ans << '\n';
  }
}