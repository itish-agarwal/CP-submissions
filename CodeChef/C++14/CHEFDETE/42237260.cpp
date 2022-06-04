#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
vector<vector<int>> g;
vector<int> ans;

void dfs(int a, int parent) {
  if((int)g[a].size()==1 && g[a][0]==parent) {
    ans.push_back(a);
  }
  for(auto b : g[a]) {
    if(b != parent) {
      dfs(b, a);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  g.resize(n + 1);
  int root = 1;
  for(int i = 1; i <= n; ++i) {
    int par;
    cin >> par;
    if(!par) root = i;
    else {
      g[par].push_back(i);
      g[i].push_back(par);
    }
  }
  dfs(root, -1);
  sort(ans.begin(), ans.end());
  for(int x : ans) cout << x << " ";
  cout << '\n';
  return 0;
}
