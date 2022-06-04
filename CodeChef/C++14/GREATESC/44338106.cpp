#include <bits/stdc++.h>
 
using namespace std;
const int INF = 2e9 + 7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while(m--) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s, t;
  cin >> s >> t;
  --s;
  --t;
  vector<int> dist(n, INF);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto v : g[u]) {
      if(dist[v] >= INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  cout << (dist[t] >= INF ? 0 : dist[t]) << '\n';
}
  
