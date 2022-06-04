#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll power(ll a, ll b) {
  if(b==0) return 1;
  ll res = power(a, b/2);
  res *= res;
  res %= mod;
  if(b&1) {
    res *= a;
    res %= mod;
  }
  return res;
}
void add_self(ll& a, ll b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll s;
  cin >> s;
  if(s < 3) {
    cout << "0\n";
    return 0;
  }
  vector<int> dp(s + 1, 1);
  dp[0] = dp[1] = dp[2] = 0;
  for(int i = 4; i <= s; i++) {
    for(int sub = 3; sub <= i; sub++) {
      dp[i] += dp[i-sub];
      if(dp[i] >= mod) {
        dp[i] -= mod;
      }
    }
  }  
  cout << dp[s] << '\n';
  return 0;
}
