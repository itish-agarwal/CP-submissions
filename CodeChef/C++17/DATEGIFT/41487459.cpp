#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int x = 0;
    while(n--) {
      int y;
      cin >> y;
      x ^= y;
    }
    cout << x << '\n';
  }
  return 0;
}
