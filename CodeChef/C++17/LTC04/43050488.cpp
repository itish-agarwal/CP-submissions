#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    char ch;
    string s, t;
    cin >> ch >> s >> t;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(t.begin(), t.end(), t.begin(), ::tolower);
    if(ch == 'A') {
      t[0] -= 32;
      cout << s + t << '\n';
    } else if(ch == 'B') {
      cout << s + '_' + t << '\n';
    } else if(ch == 'C') {
      for(char ch : s) {
        cout << (char)(ch - 32);
      }
      cout << '_';
      for(char ch : t) {
        cout << (char)(ch - 32);
      }
      cout << '\n';
    } else if(ch == 'D') {
      s[0] -= 32;
      t[0] -= 32;
      cout << s + '-' + t << '\n';
    } else {
      for(int i = 0; i < (int)s.size(); ++i) {
        if(i % 2) {
          s[i] -= 32;
        }
      }
      for(int i = 0; i < (int)t.size(); ++i) {
        if(i % 2) {
          t[i] -= 32;
        }
      }
      cout << s << "|" << t << '\n';
    }
  }
}
