#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  string S;
  cin >> N >> S;

  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>> (12, vector<int> (2000)));

  for(int i = N; i >= 0; --i) {
    for(int last = 0; last <= 10; ++last) {
      for(int mask = 0; mask < 1 << 10; ++mask) {
        if(i == N) {
          dp[i][last][mask] = last < 10;
          continue;
        }
        if(mask & (1 << last)) {
          continue;
        }
        dp[i][last][mask] = dp[i+1][last][mask];
        int x = S[i] - 'A';
        if(x == last) {
          add_self(dp[i][last][mask], dp[i+1][last][mask]);
        }
        else {
          int new_mask = mask;
          if(last >= 0 && last < 10) {
            new_mask ^= (1 << last);
          }
          if(x != last && !(mask & (1 << x))) {
            add_self(dp[i][last][mask], dp[i+1][x][new_mask]);
          }
        }
      }
    }
  }

  cout << dp[0][10][0] << '\n';
}