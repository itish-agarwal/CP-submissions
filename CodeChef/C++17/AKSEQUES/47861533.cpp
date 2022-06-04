#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  function<int(int, int)> power = [&](int A, int B) {
    int res = 1;
    while(B > 0) {
      if(B & 1) {
        res = (res * A);
      }
      A = (A * A);
      B /= 2;
    }
    return res;
  };
  int tests;
  cin >> tests;
  while(tests--) {
    int N, a, e = 0;
    cin >> N;
    int ans = power(3LL, N);
    while(N--) {
      cin >> a;
      e += 1 - a % 2;
    }
    ans -= power(2LL, e);
    cout << ans << '\n';
  }
  return 0;
}