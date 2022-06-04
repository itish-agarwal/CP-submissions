#include <bits/stdc++.h>

using namespace std;
const int nax = 1e6 + 666;
vector<bool> ispr(nax, 1);
vector<int> dp(nax);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ispr[1] = 0;
  for(int p = 2; p*p < nax; p++) {
    if(ispr[p]) {
      for(int i = p+p; i < nax; i += p) {
        ispr[i] = 0;
      }
    }
  }
  for(int i = 5; i < nax; i++) {
    dp[i] = dp[i - 1];
    if(ispr[i] && ispr[i - 2]) {
      dp[i]++;
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}
