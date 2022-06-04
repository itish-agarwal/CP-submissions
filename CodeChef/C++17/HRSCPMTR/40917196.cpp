#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    int d[n][m], g[n][m];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        d[i][j] = 0;
      }
    }
    d[n-1][0] = 1;
    queue<pair<int, int>> q;
    q.push({n-1, 0});
    while(!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(auto it : dir) {
        int xn = x + it.first;
        int yn = y + it.second;
        if(xn>=0 && xn<n && yn>=0 && yn<m && !d[xn][yn]) {
          d[xn][yn] = d[x][y] + 1;
          q.push({xn, yn});
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> g[i][j];
      }
    }
    int N = d[0][m-1];
    multiset<int> s[N + 1];    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        s[d[i][j]].insert(g[i][j]);
      }
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
      if(*s[i].begin() == *s[i].rbegin()) {
        ++cnt;
      }
    }
    int qq;
    cin >> qq;
    while(qq--) {
      int i, j, val;
      cin >> i >> j >> val;
      --i;
      --j;
      int depth = d[i][j];
      if(*s[depth].begin() == *s[depth].rbegin()) {
        --cnt;
      }
      s[depth].erase(s[depth].find(g[i][j]));
      g[i][j] = val;
      s[depth].insert(val);
      if(*s[depth].begin() == *s[depth].rbegin()) {
        ++cnt;
      }
      if(cnt==N) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}
      
