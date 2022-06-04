#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b;
    cin >> a >> b;
    if((a+b) % 3) {
      cout << "NO\n";
    } else {
      int mx = max(a, b);
      int mn = min(a, b);
      if(mx > 2*mn) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
  }
  return 0;
}
