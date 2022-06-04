#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    cout << "1\n";
    if(n > 1) {
      int st = 2, sp = 0;
      for(int i = 2; i < n; i++) {
        cout << st;
        for(int j = 0; j < sp; j++) {
          cout << " ";
        }
        st++;
        cout << st << '\n';
        st++;
        sp++;
      }
      for(int i = 0; i < n; i++) {
        cout << st;
        st++;
      }
      cout << '\n';
    }
  }
  return 0;
}
