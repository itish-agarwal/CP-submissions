#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int N, MOD;
  cin >> N >> MOD;
 
  auto add_self = [&](int& a, int b) {
    a += b;
    if(a >= MOD) {
      a -= MOD;
    }
  };
 
  vector<int> dp(N + 1), preffix_sum(N + 1);
  dp[1] = preffix_sum[1] = 1;
 
  for(int i = 2; i <= N; ++i) {
    dp[i] = preffix_sum[i-1];
 
    int z = 2;
    while(i / z > 0) {
      int nxt = i / (i / z);
 
      add_self(dp[i], ((nxt - z + 1) * dp[i / z]) % MOD);
 
      z = nxt + 1;
    } 
 
    preffix_sum[i] = preffix_sum[i-1];
    add_self(preffix_sum[i], dp[i]);
  }
 
  cout << dp[N] << '\n';
}