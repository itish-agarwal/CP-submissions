#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;  
  string cmp;
  cin >> n >> cmp;

  vector<vector<int>> dp(n + 1, vector<int> (n + 1));
  vector<vector<int>> suff(n + 1, vector<int> (n + 1));

  dp[1][1] = 1;
  for(int j = 1; j <= n; j++) {
    suff[1][j] = 1;
  }

  for(int len = 2; len <= n; len++) {
    for(int b = 1; b <= len; b++) {
      if(cmp[len-2] == '<') {
        dp[len][b] = (suff[len-1][b-1] - suff[len-1][0] + mod) % mod;
      } 
      else {
        dp[len][b] = (suff[len-1][len-1] - suff[len-1][b-1] + mod) % mod;
      }
    }
    for(int j = 1; j <= n; j++) {
      suff[len][j] = (suff[len][j - 1] + dp[len][j]) % mod;
    }
  }

  int ans = 0;
  for(int b = 1; b <= n; b++) {
    add_self(ans, dp[n][b]);
  }

  cout << ans << '\n';
  return 0;
}