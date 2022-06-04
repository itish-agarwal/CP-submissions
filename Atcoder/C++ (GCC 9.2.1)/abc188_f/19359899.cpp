#include <bits/stdc++.h>

using namespace std;
#define int long long
map<int, int> dp;

int rec(int x, int y) {
  if(dp.count(y) > 0) {
    return dp[y];
  }
  if(y <= x) {
    dp[y] = x - y;
    return dp[y];
  }
  int ans = y - x;
  if(y % 2) {
    ans = min(ans, 2 + min(rec(x, (y+1)/2), rec(x, (y-1)/2)));
  } else {
    ans = min(ans, 1 + rec(x, y/2));
  }
  dp[y] = ans;
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  cout << rec(x, y) << '\n';
  return 0;
}
