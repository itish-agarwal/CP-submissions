#include <bits/stdc++.h>

using namespace std;
#define int long long
int ceil(int a, int b) {
  return (a + b - 1) / b;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<vector<int>> g[n+1];
  while(m--) {
    int a, b, t, k;
    cin >> a >> b >> t >> k;
    g[a].push_back({b, t, k});
    g[b].push_back({a, t, k});
  }
  const int inf = 2e18 + 7777;
  vector<int> dist(n + 1, inf);
  dist[x] = 0;
  queue<int> q;
  q.push(x);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto it : g[u]) {
      int to = it[0];
      int k = it[2];
      int time_leave = ceil(dist[u], k) * k;
      int time_takes=  it[1];      
      int maybe = time_leave + time_takes;
      if(maybe < dist[to]) {
        q.push(to);
        dist[to] = maybe;
      }
    }
  }
  if(dist[y] >= inf) {
    cout << "-1\n";
    return 0;
  }
  cout << dist[y] << '\n';
}
        
