#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> dp(n);
  dp[n - 1] = 0;
  dp[n - 2] = abs(a[n - 1] - a[n - 2]);
  for(int i = n - 3; i >= 0; --i) {
    dp[i] = min(abs(a[i] - a[i + 1]) + dp[i + 1], abs(a[i] - a[i + 2]) + dp[i + 2]);
  } 
  cout << dp[0] << '\n';
  return 0;
}
