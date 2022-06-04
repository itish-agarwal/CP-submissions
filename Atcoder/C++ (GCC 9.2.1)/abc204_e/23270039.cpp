#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n, m, best, T;
  cin >> n >> m;
  vector<vector<pair<int, pair<int, int>>>> edges(n);
  while(m--) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    u--;
    v--;
    edges[u].push_back({v, {c, d}});
    edges[v].push_back({u, {c, d}});
  }
  const int inf = 2e17 + 7;
  vector<int> d(n, inf);
  d[0] = 0;
 
  set<pair<int, int>> q;
  q.insert({0, 0});
 
  while(!q.empty()) {
    int u = q.begin()->second;
    int t = q.begin()->first;
    q.erase(q.begin());
    for(auto it : edges[u]) {
      int v = it.first;
      int c = it.second.first;
      int dd = it.second.second;
      int sq = sqrt(dd);
      if(t >= sq + 3) {
        best = t + dd/(t + 1);
        T = t;
      } else {
        best = 2e17 + 7;
        for(int tt = max(t, sq - 2); tt <= sq + 2; tt++) {
          int p = tt + dd/(tt + 1);
          if(p < best) {
            best = p;
            T = tt;
          }
        }
      }
      if(best + c < d[v]) {
        q.erase({d[v], v});
        d[v] = best + c;
        q.insert({d[v], v});
      }
    }
  }

  cout << (d[n - 1] >= inf ? -1 : d[n - 1]) << '\n';
}