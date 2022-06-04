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
    for(int i = 0; i < n; ++i) {
      int en = n - i - 1;
      int sp = n + n - 1 - en - en;
      for(int j = 1; j <= en; ++j) {
        cout << j;
      }
      while(sp--) {
        cout << "*" ;
      }
      for(int j = en; j >= 1; --j) {
        cout << j;
      }
      cout << '\n';
    }
  }
}
