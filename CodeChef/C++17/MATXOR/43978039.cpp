#include <bits/stdc++.h>

using namespace std;
#define int long long

int f(int n) {
  int r = n % 4;
  if(r == 0) return n;
  if(r == 1) return 1;
  if(r == 2) return n + 1;
  return 0;
}
int ff(int l, int r) {
  int till_r = f(r);
  if(l == 1) {
    return till_r;
  }
  return till_r ^ f(l - 1);
}
void test() {
  int n, m, k;
  cin >> n >> m >> k;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    int l = i + 1 + k;
    int r = i + m + k;
    ans ^= ff(l, r);
  }
  cout << ans << '\n';
}
signed main() {
  int T;
  cin >> T;
  while(T--) {
    test();
  }
}
