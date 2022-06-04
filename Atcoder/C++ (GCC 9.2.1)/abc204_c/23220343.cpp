#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<int> vis;

void dfs(int a, int& x) {
  if(vis[a]) 
    return;
  vis[a] = 1;
  x++;
  for(int v : edges[a]) {
    dfs(v, x);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  edges.resize(n);
  vis.resize(n);
  while(m--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    // edges[b].push_back(a);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      vis[j] = 0;
    int x = 0;
    dfs(i, x);
    ans += x;
  }
  cout << ans << '\n';
}