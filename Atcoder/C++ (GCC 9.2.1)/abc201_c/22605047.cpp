#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int ans = 0;

  set<int> k, t;

  for(int i = 0; i <= 9; i++) {
    for(int j = 0; j <= 9; j++) {
      for(int k = 0; k <= 9; k++) {
        for(int l = 0; l <= 9; l++) {
          bool ok = 1;
          for(int p = 0; p < 10; p++) {
            if(s[p] == 'o') {
              if(p!=i && p!=j && p!=k && p!=l) {
                ok = 0;
                break;
              }
            } else if(s[p] == 'x') {
              if(p==i || p==j || p==k || p==l) {
                ok = 0;
                break;
              }
            }
          }
          ans += ok;
        }
      }
    }
  }

  cout << ans << '\n';
}