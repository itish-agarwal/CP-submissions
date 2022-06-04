#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int N = n;
    n = 2*n - 1;
    vector<vector<int>> g(n, vector<int> (n, 0));
    g[N-1][N-1] = 1;
    queue<pair<int, int>> q;
    q.push({N-1, N-1});
    while(!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
          int xn = x + i, yn = y + j;
          if(xn>=0 && xn<n && yn>=0 && yn<n && g[xn][yn]<=0) {
            g[xn][yn] = g[x][y] + 1;
            q.push({xn, yn});
          }
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << g[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
