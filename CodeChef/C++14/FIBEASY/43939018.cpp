#include <bits/stdc++.h>
 
using namespace std;

int main() {
  int f[100];
  f[0] = 0;
  f[1] = 1;
  for(int i = 2; i < 100; ++i) {
    f[i] = (f[i-1] + f[i-2]) % 10;
  }
  int tt;
  cin >> tt;
  while(tt--) {
    long long n, p = 1;
    cin >> n;
    while(p*2LL <= n) {
      p *= 2LL;
    }
    cout << f[(p-1)%60] << '\n';
  }
}
