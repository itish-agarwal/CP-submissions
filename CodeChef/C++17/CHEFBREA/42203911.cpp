#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  set<ll> s;
  for(ll i = 1; i <= 10000; ++i) {
    s.insert(i*i);
  }
  while(tt--) {
    int l, b;
    cin >> l >> b; 
    int a = l * b;
    int ans = 1;
    //for(ll i = 1; i*i <= a; ++i) {
      //if(a%i == 0) {
        //ll d = i, d2 = a / i;
        //if(s.find(d) != s.end()) {
          //ans = max(ans, d);
        //}
        //if(s.find(d2) != s.end()) {
          //ans = max(ans, d2);
        //}
      //}
    //}
    for(int i = 1; i <= min(l, b); ++i) {
      if(l%i==0 && b%i==0 && a%(i*i)==0) {
        ans = max(ans, i);
      }
    }
    cout << a / (ans*ans) << '\n';
  }
  return 0; 
}
