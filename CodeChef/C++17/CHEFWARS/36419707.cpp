#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int h, p, ans = 0;
    cin >> h >> p;
    while(p > 0) {
      h -= p;
      p /= 2;
      if(h<=0) {
        ans = 1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
