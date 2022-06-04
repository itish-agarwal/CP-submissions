#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long

int ceil(int a, int b) {
  return (a + b - 1) / b;
}
  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int st, n;
  cin >> st >> n;
  for(int i = 0; i < n; i++) {
    int s = i + 1;
    int en = st + i;
    while(s--) {
      cout << en << " ";
      en--;
    }
    cout << '\n';
    st += i + 1;
  }  
  return 0;
}
    
