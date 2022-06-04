#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x;
    cin >> n >> x;
    bool possible = 0;
    for(int d1 = 1; d1*d1 <= x; d1++) {
      if(x%d1 == 0) {
        int d2 = x/d1;
        if(d1<=n && d2<=n) {
          possible = 1;
          cout << "Yes\n";
          break;
        }
      }
    }
    if(!possible) {
      cout << "No\n";
    }
  }
  return 0;
}
