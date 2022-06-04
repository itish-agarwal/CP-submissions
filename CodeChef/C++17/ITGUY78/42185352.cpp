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
    int mx = n/2 + 1;
    int st = 1;
    bool sub = 0;
    for(int i = 0; i < n; ++i) {
      if(i % 2) {
        int t = st;
        for(int j = 0; j < (n - t) ; ++j) {
          cout << "#";
        }
        for(int j = 0; j < t; ++j) {
          cout << "*";
        }
        cout << '\n';
        if(sub) st--;
        else st++;
      } else {
        int t = st;
        for(int j = 0; j < t; ++j) {
          cout << "*";
        }
        for(int j = 0; j < (n - t) ; ++j) {
          cout << "#";
        }
        cout << '\n';
        if(sub) st--;
        else st++;
      }
      if(st > mx) {
        sub = 1;
        st -= 2;
      }
    }
  }
}
