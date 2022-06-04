#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    bool ok = 1;
    int n;
    cin >> n;
    while(n--) {
      int x;
      cin >> x;
      if(x%2==0) {
        ok = 0;
      }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
