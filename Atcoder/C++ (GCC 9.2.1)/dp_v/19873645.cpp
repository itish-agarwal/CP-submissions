#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int nax = 1e5 + 677;
vector<vector<int>> g(nax);
int mod, down[nax], up[nax];
vector<int> children[nax];
vector<int> pre[nax], post[nax];

map<pair<int, int>, int> mp;
//{p, c} -> x means inside children vector of p, index of child c

int add(int a, int b) {
  return (a + b) % mod;
}

int mul(int a, int b) {
  return (ll) a * b % mod;
}

void dfs1(int u, int p) {
  int prod = 1;
  for(auto v : g[u]) {
    if(v != p) {
      dfs1(v, u);
      children[u].push_back(v);
      mp[{u, v}] = (int)children[u].size() - 1;
      prod = mul(prod, add(1, down[v]));
    }
  }
  down[u] = prod;
}
void dfs_help(int u, int p) {
  vector<int> ch = children[u];
  //cout << u << " - ";
  //for(int x : ch) cout << x <<  " ";
  if(!ch.empty()) {
    int prod = 1;
    for(int x : ch) {
      prod = mul(prod, add(1, down[x]));
      pre[u].push_back(prod);
    }
    prod = 1;
    int n = ch.size();
    for(int x : ch) {
      post[u].push_back(add(1, down[x]));
    }
    for(int i = n-2; i >= 0; i--) {
      post[u][i] = mul(post[u][i+1], post[u][i]);
    }
  }
  for(auto v : g[u]) {
    if(v != p) {
      dfs_help(v, u);
    }
  }
}
void dfs2(int u, int p) {
  if(p == -1) {
    up[u] = 1;
  } else {
    int prod = up[p];
    //for(auto child : children[p]) {
      //if(child != u) {
        //prod = mul(prod, add(1, down[child]));
      //}
    //} 
    int in = mp[{p, u}], n = children[p].size();
    int before = (in > 0 ? pre[p][in-1] : 1);
    int after = (in+1 < n ? post[p][in+1] : 1);
    prod = mul(prod, mul(before, after));
    up[u] = add(1, prod);
  }
  for(auto v : g[u]) {
    if(v != p) {
      dfs2(v, u);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> mod;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs1(1, -1);
  dfs_help(1, -1);
  dfs2(1, -1);
  for(int i = 1; i <= n; i++) {
    cout << mul(down[i], up[i]) << '\n';
  }
}
