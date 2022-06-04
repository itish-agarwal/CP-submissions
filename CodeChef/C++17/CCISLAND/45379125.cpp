#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x, y, xr, yr, d;
    cin >> x >> y >> xr >> yr >> d;
    xr *= d;
    yr *= d;
    if(xr <= x && yr <= y) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}