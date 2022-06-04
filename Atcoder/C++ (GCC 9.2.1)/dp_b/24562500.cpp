#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> h(n), dp(n, INF);
  for(int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  dp[n-1] = 0;
  for(int i = n - 2; i >= 0; --i) {
    for(int j = i + 1; j < min(n, i + k + 1); ++j) {
      dp[i] = min(dp[i], abs(h[i] - h[j]) + dp[j]);
    }
  }
  cout << dp[0] << '\n';
}