#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    bool ok = false;
    for(char ch : s) {
      if(ch=='5' || ch=='0') {
        ok = 1;
        break;
      }
    }
    cout << ok << '\n';
  }
  return 0;
}
