#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x, k, d, kk, X;
  cin >> x >> k >> d;
  kk = k;
  if(x == 0) {
    if(k&1) {
      cout << d << '\n';
    } else {
      cout << 0 << '\n';
    }
    return 0;
  }
  ll tt = (abs(x))/d;
  k -= tt;
  if(k < 0) {
    if(x<0) {      
      cout << abs(x + kk*d) << '\n';
    } else {
      cout << abs(x - kk*d) << '\n';
    }
    return 0;
  }
  if(x<0) {
    X = -x;
    X %= d;
    x = -X;
    if(k&1) {
      cout << abs(x + d) << '\n';
    } else {
      cout << abs(x) << '\n';
    }
    return 0;
  }
  x %= d;
  if(k&1) {
    cout << abs(x-d) << '\n';
  } else {
    cout << abs(x) << '\n';
  }
  return 0;
}
    
  
 
