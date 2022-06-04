#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int mn = 1e7, mx = -1;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mx = max(mx, x);
    mn = min(mn, x);
  }
  cout << mx << " " << mn << '\n';
  return 0;
}
