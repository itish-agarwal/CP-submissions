#include <bits/stdc++.h>

using namespace std;
int n, m;

bool allow(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m;
}
int dfs(int x, int y, vector<vector<int>>& g, vector<vector<bool>>& vis) {
  if(vis[x][y]) return 0;
  int ans = 1;
  vis[x][y] = 1;
  for(int xx : {-1, 0, 1}) {
    for(int yy : {-1, 0, 1}) {
      if(abs(xx) + abs(yy) == 1) {
        int xn = x + xx, yn = y + yy;
        if(allow(xn, yn) && g[xn][yn]) {
          ans += dfs(xn, yn, g, vis);
        }
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char ch;
        cin >> ch;
        g[i][j] = ch - '0';
      }
    }
    vector<vector<bool>> vis(n, vector<bool> (m));
    vector<int> c;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(!vis[i][j] && g[i][j]) {
          c.push_back(dfs(i, j, g, vis));
        }
      }
    }
    int answer = 0;
    sort(c.rbegin(), c.rend());
    int k = c.size();
    for(int i = 1; i < k; i += 2) {
      answer += c[i];
    }
    cout << answer << '\n';
  }
}