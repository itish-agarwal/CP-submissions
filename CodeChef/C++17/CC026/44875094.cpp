#include <bits/stdc++.h>

using namespace std;
#define int long long 

int solve(vector<vector<int>>& g) {
    int n = g.size();
    int m = g[0].size();
    const int inf = 2e9 + 68679;
    vector<int> k0(m), k1(m), dp(m);//k0-> j>=k //k1-> j<=k
    for(int j = 0; j < m; j++) {
        k0[j] = g[n-1][j] + j;
        k1[j] = g[n-1][j] - j;
        dp[j] = g[n-1][j];
    }
    for(int i = 1; i < m; i++) {
        k0[i] = max(k0[i], k0[i-1]);
    }
    for(int i = m-2; i >= 0; i--) {
        k1[i] = max(k1[i], k1[i+1]);
    }
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            dp[j] = g[i][j] + max(k0[j] - j, k1[j] + j);
        }
        for(int j = 0; j < m; j++) {
            k0[j] = dp[j] + j;
            k1[j] = dp[j] - j;
        }
        for(int i = 1; i < m; i++) {
            k0[i] = max(k0[i], k0[i-1]);
        }
        for(int i = m-2; i >= 0; i--) {
            k1[i] = max(k1[i], k1[i+1]);
        }
    }
    int ans = -inf;
    for(int i = 0; i < m; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n));
    for(auto& it : g) {
      for(auto& itt : it) {
        cin >> itt;
      }
    }
    cout << solve(g) << '\n';
  }
}