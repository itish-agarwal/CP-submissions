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
    string s, t;
    cin >> s >> t;
    s = "0" + s;
    t = "0" + t;
    ++n;
    int l1 = -1, l2 = -1;
    for(int i = n - 1; i >= 0; i--) {
      if(s[i] == '1' && l1 <= -1) l1 = i;
      if(t[i] == '1' && l2 <= -1) l2 = i;
    }
    int even = 0, odd = 0;
    if(l1 == n - 1) {
      if(l2 == n - 1) {
        //....1
        //....1
        int x = n + n, y = n + n;
        int one = -1, two = -1;
        for(int i = n - 1; i >= 0; i--) {
          if(s[i] == '0' && one == -1) one = i;
          if(t[i] == '0' && two == -1) two = i;
        }
        x = n - 1 - one;
        y = n - 1 - two;
        odd = min(x, y);
      } else {
        //......1
        //......0
        int candidate = n - 1 - l2;
        for(int i = n - 1; i >= 0; i--) {
          if(s[i] == '0') {
            candidate = min(candidate, n - 1 - i);
          }
        }
        even = candidate;
      }
    } else {
      if(l2 == n - 1) {
        //..........0
        //..........1
        int candidate = n - 1 - l1;
        for(int i = n - 1; i >= 0; i--) {
          if(t[i] == '0') {
            candidate = min(candidate, n - 1 - i);
          }
        }
        even = candidate;
      } else {
        //....0
        //....0
        odd = min(n - 1 - l1, n - 1 - l2);
      }
    }
    cout << even << " " << odd << '\n';
  }
}