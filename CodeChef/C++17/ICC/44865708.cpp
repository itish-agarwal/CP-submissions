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
    string ans = s.substr(0, 1);
    int l = 1, n = s.size();
    for(int i = 1; i < n; ++i) {
      if(s[i] == s[i-1]) {
        l++;
      } else {
        if(l > (int)ans.size()) {
          char ch = s[i - 1];
          ans = "";
          while(l--) {
            ans.push_back(ch);
          }
        }
        l = 1;
      }
    }
    if(l > (int)ans.size()) {
      char ch = s.back();
      ans = "";
      while(l--) {
        ans.push_back(ch);
      }
    }
    cout << (int) ans.size() << " " << ans.back() << '\n';
  }
}