#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
const int mod = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int nax = 2e7 + 3;
  int dp[nax][2];
  dp[1][0] = dp[1][1] = 1;
  dp[2][0] = dp[2][1] = 2;
  dp[3][0] = 4;
  dp[3][1] = 3;
  for(int i = 4; i < nax; ++i) {
    dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
    dp[i][1] = (dp[i-1][1] + dp[i-1][0] - dp[i-2][1] + mod) % mod;
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % mod << '\n';
  }
}
