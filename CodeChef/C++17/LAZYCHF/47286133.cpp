#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x, m, d;
    cin >> x >> m >> d;
    cout << min(m * x, d + x) << '\n';
  }
}