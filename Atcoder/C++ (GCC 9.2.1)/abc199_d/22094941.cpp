#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
const int nax = 23;
vector<vector<int>> g(nax);
vector<int> vis(nax);
int n, e, res;
 
void dfs(int a, vector<int>& c) {
  if(vis[a]) return;
  c.push_back(a);
  vis[a] = true;
  for(int b : g[a]) {
    dfs(b, c);
  }
}
void check(vector<int>& component, vector<int>& color) {
  bool ok = 1;
  for(int node : component) {
    for(int x : g[node]) {
      if(color[node] == color[x]) {
        ok = 0;
        break;
      }
    }
  }
  res += ok;
}
void rec(int last_color, int in, vector<int>& component, vector<int>& color) {
  if(in == (int)component.size()) {
     check(component, color);
    return;
  }
  vector<int> forbid(3);
  for(int x : g[component[in]]) {
    if(color[x] > -1) {
      forbid[color[x]] = 1;
    }
  }
  for(int c = 0; c < 3; c++) {
    if(!forbid[c]) {
      color[component[in]] = c;
      rec(c, in + 1, component, color);
      color[component[in]] = -1;
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> e;
  while(e--) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      vector<int> component;
      dfs(i, component);

      res = 0;
      vector<int> color(n + 1, -1);
      int vertex = component[0];
      color[vertex] = 0;
      rec(0, 1, component, color);
      
      color[vertex] = 1;
      rec(1, 1, component, color);
 
      color[vertex] = 2;
      rec(2, 1, component, color);
 
      ans *= res;
      res = 0;
    }
  }
  cout << ans << '\n';
  return 0;
}