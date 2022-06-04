#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 7;
const int LOG = 25;

vector<int> edges[nax];
vector<int> depth(nax), par(nax);
vector<vector<int>> up(nax, vector<int> (LOG));

void dfs(int a, int pr) {
  for(int b : edges[a]) {
    if(b != pr) {
      par[b] = a;
      up[b][0] = a;
      depth[b] = depth[a] + 1;
      for(int j = 1; j < LOG; j++) {
        up[b][j] = up[ up[b][j-1] ][j-1];
      }
      dfs(b, a);
    }
  }
}
int get_dist(int a, int b) {
  //make a deeper
  if(depth[b] > depth[a]) {
    swap(a, b);
  }
  int res = 0;
  int k = depth[a] - depth[b];
  for(int j = LOG - 1; j >= 0; j--) {
    if(k & (1 << j)) {
      a = up[a][j];
      res += (1 << j);
    }
  }
  if(a == b) {
    return res;
  }
  for(int j = LOG - 1; j >= 0; j--) {
    if(up[a][j] != up[b][j]) {
      a = up[a][j];
      b = up[b][j];
      res += (1 << (j + 1));
    }
  }
  return res + 2;
}
int kth_ancestor(int a, int k) {
  for(int j = LOG - 1; j >= 0; j--) {
    if(k & (1 << j)) {
      a = up[a][j];
    }
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i <= n; i++) {
      par[i] = i;
      depth[i] = 0;
      edges[i].clear();
      for(int j = 0; j < LOG; j++) {
        up[i][j] = 1;
      }
    }
    for(int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    dfs(1, -1);
    //cout << up[3][0] << '\n';
    //cout << kth_ancestor(3, 1) << '\n';
    while(q--) {
      int k;
      cin >> k;
      vector<int> x(k);
      for(int i = 0; i < k; i++) {
        cin >> x[i];
      }
      int d = -1, deepest_node = -1;
      for(int node : x) {
        if(depth[node] > d) {
          d = depth[node];
          deepest_node = node;
        }
      }
      int other_end = -1, dist = 0;
      for(int node : x) {
        if(get_dist(node, deepest_node) > dist) {
          dist = get_dist(node, deepest_node);
          other_end = node;
        }
      }
      if(deepest_node == -1 || other_end == -1) {
        cout << 1 << " " << deepest_node + other_end + 1 << '\n';
      } else {
        set<int> ans;
        int go_up = dist / 2;
        int p = kth_ancestor(deepest_node, go_up);
        ans.insert(p);
        if(dist % 2) {
          ans.insert(par[p]);
        }        
        cout << (int)ans.size() << " ";
        for(int p : ans) cout << p <<  " ";
        cout << '\n';
      }
    }
  }
}
