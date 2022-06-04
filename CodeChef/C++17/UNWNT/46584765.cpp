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
    int ans = n;

    for(int l = 1; l <= 9; l++) {
      for(int d = 1; d <= 9; d++) {
        string s = "";
        for(int j = 0; j < l; j++) {
          s.push_back(d + '0');
        }
        int c = stoi(s);
        if(c <= n) {
          ans -= 1;
        }
      }
    }

    cout << ans << '\n';
  }
}