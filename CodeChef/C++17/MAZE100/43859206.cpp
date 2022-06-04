#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> go{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int g[6][6], vis[6][6];

void dfs(int x, int y) {
  if(vis[x][y]) return;
  vis[x][y] = true;
  for(auto it : go) {
    int xn = x + it.first;
    int yn = y + it.second;
    if(xn>=0 && yn>=0 && xn<6 && yn<6 && !g[xn][yn]) {
      dfs(xn, yn);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int i = 0; i < 6; ++i) {
    for(int j = 0; j < 6; ++j) {
      cin >> g[i][j];
    }
  }
  if(g[0][0] || g[5][5]) {
    cout << "No\n";
    return 0;
  }
  dfs(0, 0);
  if(vis[5][5]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
  
  
