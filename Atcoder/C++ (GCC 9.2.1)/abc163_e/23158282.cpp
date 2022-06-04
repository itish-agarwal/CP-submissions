#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a;
  cin >> n;
  vector<pair<int, int>> x;
  for(int i = 0; i < n; i++) {
    cin >> a;
    x.emplace_back(a, i);
  }
  sort(x.begin(), x.end());
  reverse(x.begin(), x.end());
  const long long inf = 2e16 + 7;
  vector<vector<long long>> dp(n, vector<long long> (n));
  for(int l = n - 1; l >= 0; l--) {
    for(int r = l; r < n; r++) {
      int id = n - (r - l + 1);
      if(l == r) {
        dp[l][r] = (long long)x[id].first * abs(l - x[id].second);
        continue;
      }
      long long k0 = (long long)x[id].first * abs(l - x[id].second) + dp[l + 1][r];
      long long k1 = (long long)x[id].first * abs(r - x[id].second) + dp[l][r - 1];
      dp[l][r] = max(k0, k1);
    }
  }
  cout << dp[0][n - 1] << '\n';
}