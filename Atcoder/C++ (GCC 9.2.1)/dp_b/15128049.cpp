#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> dp(n, 0);
  for(int i = n - 2; i >= max(0, n - k); --i) {
    dp[i] = abs(a[i] - a[n - 1]);
  }
  for(int i = n - k - 1; i >= 0; --i) {
    int bar = (int)2e9;
    for(int j = i + 1; j <= i + k; j++) {
      bar = min(bar, abs(a[i] - a[j]) + dp[j]);
    }
    dp[i] = bar;
  }
  cout << dp[0] << '\n';
  return 0;
}
