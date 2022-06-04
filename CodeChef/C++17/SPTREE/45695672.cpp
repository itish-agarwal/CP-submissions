#include <bits/stdc++.h>

using namespace std;

const int nax = 2e5 + 7;
const int LOG = 25;
vector<vector<int>> edges(nax);
vector<vector<int>> up(nax, vector<int> (LOG));
vector<int> special(nax);
vector<int> value(nax);
vector<int> depth(nax);
vector<int> par(nax);

void dfs(int u, int parent) {
  par[u] = parent;
  for(int v : edges[u]) {
    if(v != parent) {
      up[v][0] = u;
      depth[v] = depth[u] + 1;
      for(int j = 1; j < LOG; j++) {
        up[v][j] = up[ up[v][j - 1] ][j - 1];
      }
      dfs(v, u);
    }
  }
}
void dfs_v(int u, int parent) {
  for(int v : edges[u]) {
    if(v != parent) {
      dfs_v(v, u);
      if(value[v] > -1) {
        value[u] = value[v];
      }
    }
  }
  if(value[u] == -1 && special[u]) {
    value[u] = u;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;

  while(tt--) {

    int N, K, root;
    cin >> N >> K >> root;

    for(int i = 0; i <= N; i++) {
      edges[i].clear();
      for(int j = 0; j < LOG; j++) {
        up[i][j] = root;
      }
      special[i] = false;
      value[i] = -1;
      depth[i] = 0;
      par[i] = -1;
    }

    for(int i = 0; i < K; i++) {
      int node;
      cin >> node;
      special[node] = true;
    }

    for(int i = 1; i < N; i++) {  
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }

    dfs(root, -1);
    
    dfs_v(root, -1);

    vector<int> S;
    for(int i = 1; i <= N; i++) {
      int x = i;
      if(value[x] == -1) {
        for(int j = LOG - 1; j >= 0; j--) {
          if(value[up[x][j]] == -1) {

            x = up[x][j];
          }
        }
        x = par[x];
        cout << 2*depth[x] - depth[i] << " ";
        S.push_back(value[x]);
      } else {
        cout << depth[i] << " ";
        S.push_back(value[i]);
      }
    }
    cout << '\n';
    for(auto& s : S) 
      cout << s << " " ;
    cout << '\n';
  }
}