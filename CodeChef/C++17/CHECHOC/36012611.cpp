#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, m, x, y, ans = 0;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    if(m==1 && n==1) ans = x;
    else {
      int mul = max((n*m)/2, (n*m) - (n*m)/2);
      int other = (n*m) - mul;
      for(int pos = 0; pos <= x; pos++) {
        for(int q = 0; q <= min(x, y - pos); q++) {
          ans = max(ans, pos*mul + q*other);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
