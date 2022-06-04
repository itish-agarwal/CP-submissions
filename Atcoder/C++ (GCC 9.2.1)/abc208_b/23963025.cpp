#include <bits/stdc++.h>

using namespace std;
#define int long long

int fac(int n) {
  int res = 1;
  for(int i = 1; i <= n; i++)
    res *= i;
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int P;
  cin >> P;
  int ans = 0, x = 10;
  while(P > 0) {
    int need = min(100LL, P / fac(x));
    P -= need * fac(x);
    ans += need;
    x--;
  }
  cout << ans << '\n';
} 
