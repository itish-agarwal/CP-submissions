#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r, d, dd;
  cin >> l >> r >> d;
  int ans = 0;
  for(int i = l; i <= r; i++) {
    if(i%d == 0) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
