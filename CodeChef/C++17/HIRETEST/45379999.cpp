#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int f = 0, u = 0, p = 0;
      for(char ch : s) {
        if(ch == 'F') f++;
        else if(ch == 'U') u++;
        else p++;
      }
      if(f >= x || (f == x-1 && p >= y)) cout << 1;
      else cout << 0;
    }
    cout << '\n';
  }
}