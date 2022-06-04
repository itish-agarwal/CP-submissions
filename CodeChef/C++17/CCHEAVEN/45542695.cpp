#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int good = 0;
    bool ok = 0;
    for(int i = 0; i < n; i++) {
      int need = (i + 1) / 2 + (i + 1) % 2;
      good += (s[i] == '1');
      if(good >= need) {
        cout << "YES\n";
        ok = true;
        break;
      }
    }
    if(!ok) {
      cout << "NO\n";
    }
  }
}