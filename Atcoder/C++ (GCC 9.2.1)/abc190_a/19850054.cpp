#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if(c == 0) {
    if(a <= b) {
      cout << "Aoki\n";
    } else {
      cout << "Takahashi\n";
    }
  } else {
    if(b <= a) {
      cout << "Takahashi\n";
    } else {
      cout << "Aoki\n";
    }
  }
  return 0;
}
