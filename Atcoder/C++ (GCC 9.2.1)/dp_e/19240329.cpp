#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18 + 34567;

void min_self(ll& a, ll b) {
  a = min(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W, V = 0;
  cin >> n >> W;
  vector<int> w(n), v(n);
  for(int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
    V += v[i];
  }
  vector<ll> dp(V + 1, inf);
  dp[0] = 0;
  for(int i = 0; i < n; i++) {
    for(int vt = V - v[i]; vt >= 0; vt--) {
      min_self(dp[vt + v[i]], dp[vt] + w[i]);
    }
  }
  for(int i = V; i >= 0; i--) {
    if(dp[i] <= W) {
      cout << i << '\n';
      goto done;
    }
  }
  done: return 0;
}
    
  
