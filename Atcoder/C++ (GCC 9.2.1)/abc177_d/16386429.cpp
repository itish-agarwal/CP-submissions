#include <bits/stdc++.h>

using namespace std;
const int nax = 2e5 + 5;
vector<int> g[nax];
bool visited[nax];

void dfs(int u, int& tmp) {
  if(visited[u]) {
    return;
  }
  visited[u]=1;
  tmp++;
  for(int v : g[u]) {
    dfs(v, tmp);
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, e;
  cin >> n >> e;
  while(e--) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      int tmp = 0;
      dfs(i, tmp);
      ans = max(ans, tmp);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
  
