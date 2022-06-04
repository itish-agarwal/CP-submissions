#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    long long n;
    cin >> n;
    long long answer = 0, p = 1;
    while(p <= n) {
      answer++;
      p *= 2;
    }
    cout << answer << '\n';
  }
  return 0;
}
