#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  for(int x = 0; x <= k; x++) {
    for(int y = 0; y <= k; y++) {
      if(x + y <= k) {
        int bb = b*pow(2, x);
        int cc = c*pow(2, y);
        if(bb>a && cc>bb) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}
