#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, N;
  cin >> H >> N;
  vector<int> A(N), B(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  const int inf = 2e9 + 7;
  vector<vector<int>> dp(N + 1, vector<int> (H + 1, inf));
  for(int i = N; i >= 0; i--) {
    for(int j = 0; j <= H; j++) {
      if(i == N) {
        dp[i][0] = 0;
        continue;
      }
      if(j == 0) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = min(dp[i + 1][j], B[i] + dp[i][max(0, j - A[i])]);
    }
  }
  cout << dp[0][H] << '\n';
  return 0;
}