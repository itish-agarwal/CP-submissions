#include <bits/stdc++.h>

using namespace std;
 
const long long inf = (long long) 2e16 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<long long> ll(N), preffix_max(N);
    for(int i = 0; i < N; i++) {
      cin >> A[i];
      ll[i] = A[i];
      preffix_max[i] = A[i];
      if(i > 0) {
        ll[i] = A[i] + max(0LL, ll[i - 1]);
        preffix_max[i] = max(preffix_max[i - 1], ll[i]);
      }
    }
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>> (K + 1, vector<long long> (2, -inf)));
    for(int i = 0; i < N; i++) {
      for(int j = 1; j <= K; j++) {
        for(int k = 0; k < 2; k++) {
          if(i == 0) {
            if(j == 1) {
              dp[i][j][k] = A[i];
            } else {
              dp[i][j][k] = -inf;
            }
            continue;
          }
          if(j == 1) {
            dp[i][j][k] = preffix_max[i];
            continue;
          }
          long long &ans = dp[i][j][k];
          if(k == 1) {
            ans = max(ans, dp[i - 1][j - 1][0]);
          } else {
            ans = max(ans, dp[i - 1][j][0]);
          }
          ans = max(ans, A[i]*j + dp[i - 1][j][1]);
          ans = max(ans, A[i]*j + dp[i - 1][j - 1][0]);
        }
      }
    }
    cout << dp[N - 1][K][0] << '\n';
  }
}