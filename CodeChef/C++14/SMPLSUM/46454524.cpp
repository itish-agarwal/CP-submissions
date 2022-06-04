#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int nax = 1e7 + 3;

vector<int> lpf(nax);

int power(int a, int b) {
  if(b == 0) {
    return 1;
  }
  int res = power(a, b/2);
  res = (res * res);
  if(b % 2) {
    res = (res * a);
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  iota(lpf.begin(), lpf.end(), 0);

  for(int i = 2; i < nax; i++) {
    if(lpf[i] == i) {
      for(int j = i + i; j < nax; j += i) {
        lpf[j] = min(lpf[j], i);
      }
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = 1;
    while(n > 1) {
      int p = lpf[n];
      int t = 0;
      while(n%p == 0) {
        n /= p;
        t++;
      }
      if(t == 1) {
        int mul = (p + 1) * (p + 1) - 3LL*p;
        ans *= mul;
      } else {
        int mul = (power(p, t+t+1) + 1) / (p + 1);
        ans *= mul;
      }
    }
    cout << ans << '\n';
  }
}