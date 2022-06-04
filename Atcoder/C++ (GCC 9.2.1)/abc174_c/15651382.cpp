#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, d, ans = 0;
  cin >> n >> d;
  while(n--) {
    long long x, y;
    cin >> x >> y;
    long long dd = x*x + y*y;
    if(dd <= d*d) ans++;
  }
  cout << ans << '\n';
  return 0;
}
