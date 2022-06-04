#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N;
    cin >> N;
    int ans = -2e8 - 7;
    vector<int> A(N), dp(N);
    for(int i = 0; i < N; i++) {
      cin >> A[i];
      if(i > 0) 
        dp[i] = A[i] + max(0LL, dp[i - 1]);
      else
        dp[i] = A[i];
      ans = max(ans, dp[i]);
    }
    if(ans > 0) {
      cout << "Can study - ";
    } else {
      cout << "Cannot study - ";
    }
    cout << ans << '\n';
  }
}
