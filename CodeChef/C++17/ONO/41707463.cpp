#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int n = s.size();
    int odd = 0, sum = 0;
    for(char ch : s) {
      sum += ch-'0';
      if((ch-'0')%2) {
        odd++;
      }
    }
    if(odd > 0) {
      int answer = 0;
      if(sum % 2) {
        if(odd == 1) {
          answer = -1;
        } else {
          answer = 1;
        }
      }
      cout << answer << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
