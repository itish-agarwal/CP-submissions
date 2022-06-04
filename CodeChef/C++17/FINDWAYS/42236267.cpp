#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
vector<vector<int>> g;
vector<int> a;
int n, m, answer;

void dfs(int u, int parent, int c) {
  //check if leaf;
  if((int)g[u].size()==1 && g[u][0]==parent) {
    answer++;
  }
  for(auto v : g[u]) {
    if(v != parent) {
      if(!a[v]) {
        dfs(v, u, 0);
      } else {
        if(c + 1 < m) {
          dfs(v, u, c + 1);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  g.resize(n + 1);
  a.resize(n + 1);
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1, a[1]);
  cout << answer << '\n';
  return 0;
}
