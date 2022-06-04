#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long

const int nax = 1e5 + 7;
int down[nax], up[nax], score[nax];
vector<vector<int>> g(nax), children(nax);

//find highest score of any connected component
void dfs_1(int a, int parent) {
  down[a] = score[a];
  for(auto b : g[a]) {
    if(b != parent) {
      dfs_1(b, a);
      children[a].push_back(b);
      down[a] += max(0LL, down[b]);
    }
  }
}
void dfs_2(int a, int parent) {
  up[a] = score[a];
  if(parent != -1) {
    up[a] = score[a];
    int more = up[parent] + score[a];
    for(auto b : children[parent]) {
      if(b != a) {
        more += max(0LL, down[b]);
      }
    }
    up[a] = max(up[a], more);
  }
  for(auto b : g[a]) {
    if(b != parent) {
      dfs_2(b, a);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
      g[i].clear();
      children[i].clear();
    }
    for(int i = 1; i <= n; ++i) cin >> score[i];
    for(int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs_1(1, -1);
    dfs_2(1, -1);
    int ans = score[1];
    for(int i = 1; i <= n; ++i) {
      ans = max(ans, score[i]);
      ans = max(ans, down[i]);
    }
    cout << ans << '\n';
  }
}

