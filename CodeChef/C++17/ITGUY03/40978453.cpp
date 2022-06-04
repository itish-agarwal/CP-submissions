#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    bool ok = false;
    for(char ch : s) {
      int d = ch - '0';
      if(d%2 == 0) {
        ok = true;
        break;
      }
    }
    cout << ok << '\n';
  }
  return 0;
}
