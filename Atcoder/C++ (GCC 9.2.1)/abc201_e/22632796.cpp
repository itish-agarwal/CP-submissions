#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 1e9 + 7;

vector<vector<pair<int, int>>> edges;
vector<int> A;

// void dfs(int u, int p, int w, int x) {
//   A[u] = (w ^ x);
//   for(auto it : edges[u]) {
//     int v = it.first;
//     int wt = it.second;
//     if(v != p) {
//       dfs(v, u, wt, A[u]);
//     }
//   }
// }
void dfs(int u, int ans, int par) {
  A.push_back(ans);
  for(auto it : edges[u]) {
    int v = it.first;
    int w = it.second;
    if(v != par) {
      dfs(v, (ans ^ w), u);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 

  int N;
  cin >> N;
  edges.resize(N);

  for(int i = 1; i < N; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a -= 1;
    b -= 1;
    edges[a].push_back({b, w});
    edges[b].push_back({a, w});
  }

  dfs(0, 0, 0);

  int ans = 0;

  for(int i = 0; i <= 60; i++) {
    int z = 0, c = 0;
    for(int j = 0; j < N; j++) {
      if(A[j]%2 == 0) {
        z++;
      } else {
        c++;
      }
      A[j] /= 2;
    }
    ans = (ans + ((z * c) % mod * ((1ll << i) % mod)) % mod) % mod;
  }

  cout << ans << endl;
}