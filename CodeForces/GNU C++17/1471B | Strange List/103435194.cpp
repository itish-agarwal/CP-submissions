#include <bits/stdc++.h>
 
using namespace std;
#define int int64_t
 
int ceil(int a, int b) {
  return (a + b - 1)/b;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x, k, ans = 0;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      k = a[i];
      while(k%x == 0) {
        b[i]++;
        k /= x;
      }
    }
    int mn = 10000, in = -1;
    for(int i = 0; i < n; i++) {
      if(b[i] < mn) {
        mn = b[i];
        in = i;
      }
    }
    int s = 0;
    for(int x : a) {
      s += x;
    }
    ans = (mn + 1)*s;
    for(int i = 0; i < n; i++) {
      if(i < in) {
        ans += a[i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}