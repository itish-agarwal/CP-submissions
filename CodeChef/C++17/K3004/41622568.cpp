#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
vector<vector<int>> g;
int n, m;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

vector<int> dp;

int rec(int u) {
  if(u == n) return 1;
  if(dp[u] <= -1) {      
    int answer = 0;
    for(int v : g[u]) {
      if(rec(v) > 0) {
        add_self(answer, rec(v));
      }
    }
    dp[u] = answer;
  }
  return dp[u];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  g.resize(n+1);
  dp.assign(n+1, -1);
  while(m--) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
  }
  cout << rec(1) << '\n';
  return 0;
}
  
