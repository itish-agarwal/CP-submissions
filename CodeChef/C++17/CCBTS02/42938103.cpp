#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    bool run = false;
    bool error = false;
    while(n--) {
      string s;
      cin >> s;
      if(s == "start") {
        run = 1;
      } else if(s == "restart") {
        run = 1;
      } else {
        if(!run) {
          error = true;
        } else {
          run = 0;
        }
      }
    }
    cout << (error ? "404\n" : "200\n");
  }
}
