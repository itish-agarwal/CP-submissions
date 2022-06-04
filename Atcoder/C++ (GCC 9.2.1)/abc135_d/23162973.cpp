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
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<int>> dp(N + 1, vector<int> (13));
  for(int i = N; i >= 0; i--) {
    for(int rem = 0; rem < 13; rem++) {
      if(i == N) {
        dp[i][5] = 1;
        continue;
      }
      if(S[i] != '?') {
        int d = S[i] - '0';
        dp[i][rem] = dp[i + 1][(rem * 10 + d)%13];
      } else {
        for(int d = 0; d <= 9; d++) {
          add_self(dp[i][rem], dp[i + 1][(rem * 10 + d)%13]);
        }
      }
    }
  }
  cout << dp[0][0] << '\n';
}