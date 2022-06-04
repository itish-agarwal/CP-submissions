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
  int n, T;
  cin >> n >> T;
  vector<int> a(n);
  for(auto& it : a) cin >> it;
  int tail = 0, head = -1, s = 0, cnt = 0;
  while(tail < n) {
    while(head+1<n && s+a[head+1]<=T) {
      head++;
      s += a[head];
    }
    cnt += max(0LL, head - tail + 1);
    if(head >= tail) s -= a[tail];
    if(head < tail) {
      head++;
    }
    tail++;
  }
  //cout << cnt << '\n';
  int den = n*(n+1)/2;
  double denn = 1.0L * den;
  double numm = 1.0L * cnt;
  printf("%g\n", numm / denn);
  return 0;
}
