#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n), dp(n);
  for(int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  for(int i = n - 2; i >= 0; --i) {
    dp[i] = abs(h[i] - h[i+1]) + dp[i+1];
    if(i + 2 < n) {
      dp[i] = min(dp[i], abs(h[i] - h[i+2]) + dp[i+2]);
    }
  }
  cout << dp[0] << '\n';
}