#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif
 
using namespace std;
int a[101], ans[101];
 
void rec(int l, int r, int d) {
  if(l > r) return;
  int mx = -1, in = -1;
  for(int i = l; i <= r; ++i) {
    if(a[i] > mx) {
      mx = a[i];
      in = i;
    }
  }
  ans[in] = d;
  rec(l, in-1, d+1);
  rec(in+1, r, d+1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    rec(0, n-1, 0);
    for(int i = 0; i < n; ++i) {
      cout << ans[i] << " " ;
    }
    cout << '\n';
  }
}