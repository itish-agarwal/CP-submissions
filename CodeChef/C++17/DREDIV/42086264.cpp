#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long

void test_case() {
  int n, k;
  cin >> n >> k;
  while(k%2 == 0) {
    k /= 2;
  }
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int x : a) {
    if(x % k) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;  
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
}
