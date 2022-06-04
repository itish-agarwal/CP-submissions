#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    long long n, x;
    cin >> n;
    x = n;
    long long b = 0, xx = 0;
    while(x > 0) {
      b += 1;
      xx ^= (x % 2);
      x /= 2;
    }
    cout << (b ^ xx) % 2 << '\n';
  }
}