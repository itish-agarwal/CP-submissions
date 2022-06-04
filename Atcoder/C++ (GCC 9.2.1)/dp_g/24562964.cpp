#include <bits/stdc++.h>

using namespace std;

vector<int> topological_sort(const vector<vector<int>>& edges) {
  int n = edges.size();
  vector<int> in_degree(n);
  vector<int> order;

  for(int i = 0; i < n; ++i) 
    for(int lead : edges[i]) 
      in_degree[lead]++;

  for(int i = 0; i < n; ++i) 
    if(in_degree[i] == 0) 
      order.push_back(i);

  int cur = 0;

  while(cur < (int) order.size()) {
    int a = order[cur++];

    for(int b : edges[a])
      if(--in_degree[b] == 0)
        order.push_back(b);
  }

  return order;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, e;
  cin >> n >> e;
  vector<vector<int>> edges(n);
  for(int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    edges[a].push_back(b);
  }
  int ans = 0;
  vector<int> order = topological_sort(edges);
  vector<int> dp(n);
  for(int i = n - 1; i >= 0; --i) {
    int node = order[i];
    for(int nbr : edges[node]) {
      dp[node] = max(dp[node], dp[nbr] + 1);
    }
    ans = max(ans, dp[node]);
  }
  cout << ans << '\n';
}