#include <bits/stdc++.h>

using namespace std;

const int nax = 405;
int dp[nax][nax];
int n, k, a[nax];

int rec(int in, int k) {
  if(dp[in][k] > -1) {
    return dp[in][k];
  }
  if(k <= 0 || n-in+1 <= 1) {
    dp[in][k] = 0;
    return 0;
  }
  int ans = rec(in + 1, k);
  if(k >= 2) {
    for(int i = in + 1; i < n; ++i) {
      int p = a[i] - a[in];
      ans = max(ans, p + rec(i + 1, k - 2));
    }
  }
  dp[in][k] = ans;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  cout << rec(0, k) << endl;
}