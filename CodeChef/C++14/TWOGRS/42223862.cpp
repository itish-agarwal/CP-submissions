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
    int A, B, C;
    cin >> A >> B >> C;
    int a = A + 2*B + 3*C;
    if(a & 1) {
      cout << "NO\n";
    } else {
      bool ok = 1;
      int x = A > 0;
      int y = B > 0;
      int z = C > 0;
      if(x + y + z == 1) {
        //two are zero
        if(x) {
          if(A & 1) ok = 0;
          else ok = 1;
        } else if(y) {
          if(B & 1) ok = 0;
          else ok = 1;
        } else {
          if(C & 1) ok = 0;
          else ok = 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
      } else {
        if(A == 0) {
          //C is always even
          if(B & 1) {
            if(B == 1) {
              ok = 0;
            }
          }          
        } else if(B == 0) {
          if(A == 1) ok = 0;
        } else if(C == 0) {
          
        }
        cout << (ok ? "YES\n" : "NO\n");
      }
    }
  }
}
