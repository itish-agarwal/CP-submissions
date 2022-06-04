#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
const string no = "NO";

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int S, P, k;
  cin >> S >> P >> k;
  if(k == 1) {
    if(S == P) {
      cout << S << '\n';
    } else {
      cout << no << '\n';
    }
  } else if(k == 2) {
    for(int a = 1; a < S; ++a) {
      int b = S - a;
      if(a*b == P) {
        cout << a << " " << b << '\n';
        goto done;
      }
    }
  } else if(k == 3) {
    for(int a = 1; a < S; ++a) {
      for(int b = 1; b < S - a; ++b) {
        int c = S - a - b;
        if(c >= 1 && a*b*c == P) {
          cout << a << " " << b << " " << c << '\n';
          goto done;
        }
      }
    }
  } else {
    for(int a = 1; a < S; ++a) {
      for(int b = 1; b < S; ++b) {
        if(P%(a*b) == 0) {
          int prod = P / (a*b);
          int need_sum = S - a - b;
          for(int i = 1; i*i <= prod; ++i) {
            if(prod%i == 0) {
              int d1 = i, d2 = prod / i;
              if(d1 + d2 == need_sum) {
                cout << a << " " << b << " " << d1 << " " << d2 << '\n';
                goto done;
              }
            }
          }
        }
      }
    }
  }          
  cout << no << '\n';
  done: ;   
}
