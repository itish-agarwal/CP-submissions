#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> topo, indegree;

void topSort(int n) {
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    // cout << indegree[i] << " ";
    if(indegree[i]==0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for(int v : g[u]) {
      indegree[v]--;
      if(indegree[v] == 0) {
        q.push(v);
      }
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, e;
  cin >> n >> e;
  g.resize(n+1);
  indegree.resize(n+1);
  while(e--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    indegree[v]++;
  }
  //find topological sort by kahn's algo
  topSort(n);
  
  vector<int> dp(n+1), pos(n+1);
  for(int i = 1; i <= n; i++) {
    pos[topo[i-1]] = i;
  }
  int ans = 0; 
  for(int i = n-1; i >= 1; --i) {
    int u = topo[i-1];
    for(int v : g[u]) {
      int j = pos[v];
      dp[i] = max(dp[i], dp[j]+1);
    }
    ans=max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}