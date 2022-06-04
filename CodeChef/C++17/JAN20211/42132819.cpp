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
    int k = __builtin_popcount(n);
    if(k%2) {
      cout << "Non-Magical\n";
    } else {
      cout << "Magical\n";
    }
  }
  return 0;
}
