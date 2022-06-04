#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x1, x2, x3, R, ans;
    cin >> x1 >> x2 >> x3 >> R;
    if(x2 < x1) 
      swap(x1, x2);
    pair<int, int> laser = {x3 - R, x3 + R};
    pair<int, int> intersect = {max(x1, laser.first), min(x2, laser.second)};
    // cout << intersect.first << " " << intersect.second << '\n';
    if(intersect.second >= intersect.first) {
      ans = x2 - x1 + 1 - (intersect.second - intersect.first + 1);
    } else {
      ans = x2 - x1;
    }
    cout << ans << '\n';
  }
}