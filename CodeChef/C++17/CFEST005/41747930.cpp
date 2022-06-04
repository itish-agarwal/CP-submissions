#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  int A = 0, B = 0;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  int dp[2][n+1];
  dp[0][n] = dp[1][n] = 0;
  for(int i = n-1; i >= 0; i--) {
    int pos = max(dp[0][i+1], dp[1][i+1]);
    dp[0][i] = max(pos, a[i] + B);
    
    dp[1][i] = max(pos, b[i] + A);
    A = max(A, dp[0][i]);
    B = max(B, dp[1][i]);
  }
  cout << max(dp[0][0], dp[1][0]) << '\n';
  return 0;
}
