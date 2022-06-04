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
    int n = s.size();
    bool ok = 1;
    int i = 0, j = n - 1;
    while(i < j) {
      if(s[i]!=s[j]) {
        ok = 0;
        break;
      }
      i++;
      j--;
    }
    cout << (ok ? "wins\n" : "loses\n");
  }
  return 0;
}
