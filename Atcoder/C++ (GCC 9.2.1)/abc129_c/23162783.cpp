#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<bool> bad(N + 1);
  while(M--) {
    int s;
    cin >> s;
    bad[s] = true;
  }
  vector<int> dp(N + 4);
  for(int i = N; i >= 0; i--) {
    if(i == N) {
      dp[i] = (1 - bad[i]);
      continue;
    }
    dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
    if(bad[i]) {
      dp[i] = 0;
    }
  }
  cout << dp[0] << '\n';
  return 0;
}