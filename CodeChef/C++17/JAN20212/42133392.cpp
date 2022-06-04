#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int k = n % 4;
    if(k==0) cout << n << '\n';
    else if(k==1) cout << 1 << '\n';
    else if(k==2) cout << n+1 << '\n';
    else cout << 0 << '\n';
  }
  return 0;
}
