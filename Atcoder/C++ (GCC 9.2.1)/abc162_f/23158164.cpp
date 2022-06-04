#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = 2e16 + 7;
  int N;
  cin >> N;
  vector<int> A(N + 1), pref(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    if(i % 2) {
      pref[i] = pref[i - 1] + A[i];
    } else {
      pref[i] = pref[i - 1];
    }
  }
  vector<int> dp(N + 1);
  for(int i = 1; i <= N; i++) {
    if(i % 2) {
      dp[i] = dp[i - 1];
      if(i > 1) {
        dp[i] = max(dp[i], A[i] + dp[i - 2]);
      }
    } else {
      dp[i] = max(pref[i - 1], dp[i - 2] + A[i]);
    }
  }
  cout << dp[N] << '\n';
}
