#include <bits/stdc++.h>

using namespace std;

struct Tree {

  //TODO: do not forget to call run_dfs
  //TODO: sum of weights may overflow int
  vector<vector<pair<int, int>>> edges;
  vector<int> depth, par;
  int root, N;

  const int LOG = 19;
  vector<vector<int>> up, weights;

  //initialise with number of nodes, root
  Tree(int n, int r, bool is_weighted) {
    N = n;
    root = r;
    edges.resize(N);
    up = vector<vector<int>> (N, vector<int> (LOG, r));
    weights = vector<vector<int>> (N, vector<int> (LOG));
    depth.resize(N);
    par.assign(N, r);
  }

  void add_edge(int a, int b, int w = 1) {
    //TODO: check here if indexing is correct
    edges[a].push_back({b, w});
    edges[b].push_back({a, w});
  }

  void run_dfs() {
    Dfs(root, -1);
  }

  void Dfs(int a, int pr) {
    for(auto it : edges[a]) {
      int b = it.first, w = it.second;
      if(b != pr) {
        par[b] = a;
        up[b][0] = a;
        weights[b][0] = w;
        depth[b] = depth[a] + 1;
        for(int j = 1; j < LOG; j++)
          up[b][j] = up[ up[b][j - 1] ][j - 1];

        for(int j = 1; j < LOG; j++) 
          weights[b][j] = weights[b][j - 1] + weights[up[b][j - 1]][j - 1];
        Dfs(b, a);
      }
    }
  }

  //returns pair -> lca, dist between two nodes
  pair<int, int> lca_dist(int a, int b) {
    //Assumes a and b are 0 indexed
    if(depth[b] > depth[a])
      swap(a, b);

    int res = 0, k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; j--) {
      if(k & (1 << j)) {
        res += weights[a][j];
        a = up[a][j];
      }
    }

    if(a == b)
      return make_pair(a, res);

    for(int j = LOG - 1; j >= 0; j--) {
      if(up[a][j] != up[b][j]) {
        res += weights[a][j] + weights[b][j];
        a = up[a][j];
        b = up[b][j];
      }
    }
    return make_pair(par[a], res + weights[a][0] + weights[b][0]);
  }

  int kth_ancestor(int a, int k) {
    if(k > depth[a]) 
      return -1;
    for(int j = LOG - 1; j >= 0; j--) {
      if(k & (1 << j)) 
        a = up[a][j];
    }
    return a;
  }

  //ONLY FOR UNWEIGHTED TREES

  //Returns pair -> node, dist of node farthest away from sc
  pair<int, int> get_farthest_away(int sc) {
    const int INF = 2e9 + 7;
    pair<int, int> ans = {sc, 0};
    vector<int> d(N, INF);
    queue<int> pq;
    pq.push(sc);
    d[sc] = 0;
    while(!pq.empty()) {
      int u = pq.front();
      pq.pop();
      for(auto it : edges[u]) {
        int v = it.first;
        if(d[v] >= INF) {
          d[v] = d[u] + 1;
          pq.push(v);
          if(d[v] > ans.second) {
            ans = {v, d[v]};
          }
        }
      }
    }
    return ans;
  }

  //Returns pair -> node, node : ends of diameter of tree
  pair<int, int> ends_of_diameter() {
    pair<int, int> d = get_farthest_away(0);
    pair<int, int> ans = {d.first, -1};
    d = get_farthest_away(d.first);
    ans.second = d.first;
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;
  Tree tree(N, 0, 0);

  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    tree.add_edge(a, b);
  }
  tree.run_dfs();
  for(int q = 0; q < Q; ++q) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    int d = tree.lca_dist(a, b).second;
    cout << (d % 2 ? "Road" : "Town") << '\n';
  }
}