#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;
    int thief = abs(n - x) + abs(m - y);
    int police = max(n - a, m - b);
    if(police < thief) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}