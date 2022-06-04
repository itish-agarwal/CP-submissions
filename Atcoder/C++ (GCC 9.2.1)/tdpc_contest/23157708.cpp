#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int t = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    t += a[i];
  }
  sort(a.begin(), a.end());
  vector<int> dp(t + 1);
  dp[0] = 1;
  for(int x : a) {
    vector<int> beg;
    for(int i = 0; i <= t; i++) {
      if(dp[i]) {
        beg.push_back(i);
      }
    }
    for(int i : beg) {
      if(i + x <= t) {
        dp[i + x] = 1;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= t; i++) {
    ans += dp[i];
  }
  cout << ans << '\n';
}