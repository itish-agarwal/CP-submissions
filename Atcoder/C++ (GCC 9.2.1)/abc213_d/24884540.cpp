#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<int> order, vis, parent;
int cnt, leaves;

void Dfs(int a, int pr) {
  order.push_back(a);
  for(int b : edges[a]) {
    if(b != pr) {
      Dfs(b, a);
      order.push_back(a);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  edges.resize(n);
  vis.resize(n);
  parent.resize(n);
  for(int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 0; i < n; ++i) {
    sort(edges[i].begin(), edges[i].end());
  }
  Dfs(0, -1);
  for(int x : order) {
    cout << ++x << " ";
  }
  cout << '\n';
}