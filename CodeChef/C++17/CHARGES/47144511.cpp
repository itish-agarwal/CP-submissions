#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int a = 0;
    for(int i = 1; i < n; i++) {
      if(s[i] == s[i - 1]) {
        a += 2;
      } else {
        a += 1;
      }
    }
    auto get_contribution = [&](int i) {
      int r = 0;
      if(i + 1 < n) {
        if(s[i] == s[i + 1]) {
          r += 2;
        } else {
          r += 1;
        }
      }
      if(i - 1 >= 0) {
        if(s[i] == s[i - 1]) {
          r += 2;
        } else {
          r += 1;
        }
      }
      return r;
    };
    while(q--) {
      int x;
      cin >> x;
      x -= 1;
      a -= get_contribution(x);
      s[x] = (s[x] == '1' ? '0' : '1');
      a += get_contribution(x);
      cout << a << '\n';
    }
  }
}