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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> g(n+1);
    vector<bool> visited(n+1);
    reverse(a.begin(), a.end());
    for(int i = 1; i < n; i += 2) {
      int u, v;
      u = a[i-1]/2 + 1;
      v = a[i]/2 + 1;
      if(a[i-1] % 2) ++u;
      if(a[i] % 2) ++v;
      if(u^v) {
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    int res = 0;
    function<int(int)> dfs = [&](int u) {
      if(visited[u]) {
        return 0;
      }
      visited[u] = true;
      int ans = 1;
      for(int v : g[u]) {
        ans += dfs(v);
      }
      return ans;
    };
    for(int i = 1; i <= n; i++) {
      if(!visited[i]) {
        res += dfs(i) - 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
