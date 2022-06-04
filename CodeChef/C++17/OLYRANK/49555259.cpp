#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a += b + c;
    d += e + f;
    cout << (a > d ? 1 : 2) << '\n';
  }
}