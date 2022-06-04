#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  int N = S.size();
  const int mod = 2019;
  // vector<vector<long long>> dp(N, vector<long long> (mod));
  vector<long long> dp(mod);
  dp[S[0]-'0']=1;
  long long ans = dp[0];
  for(int i = 1; i < N; i++) {
    vector<long long> new_dp(mod);
    new_dp[S[i]-'0'] = 1;
    for(int j = 0; j < mod; j++) {
      int new_mod = (j * 10 + S[i] - '0') % mod;
      new_dp[new_mod] += dp[j];
    }
    ans += new_dp[0];
    dp = new_dp;
  }
  cout << ans << '\n';
}