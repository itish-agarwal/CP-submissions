#include <bits/stdc++.h>

using namespace std;

void dfs(int a, int b, vector<int>* edges, vector<bool>& visited, vector<vector<bool>>& can) {
  can[a][b] = 1;
  if(visited[b]) return;
  visited[b] = 1;
  for(int v : edges[b]) {
    can[a][v] = 1;
    dfs(a, v, edges, visited, can);
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s, t;
    cin >> s >> t;
    int m;
    cin >> m;
    vector<int> edges[27];
    while(m--) {
      string e;
      cin >> e;
      int a = e[0] - 'a';
      int b = e[3] - 'a';
      edges[a].push_back(b);
    }
    vector<vector<bool>> can(26, vector<bool> (26, 0));
    for(int i = 0; i < 26; i++) {
      vector<bool> visited(26, 0);
      dfs(i, i, edges, visited, can);
    }
    bool ok = (s.size()==t.size());
    if(ok > 0) {
      for(int i = 0; i < s.size(); i++) {
        int u = s[i]-'a';
        int v = t[i]-'a';
        if(!can[u][v]) {
          ok = 0;
          break;
        }
      }
    }
    if(ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
