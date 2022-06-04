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
  int p, i, m, r;
  cin >> p >> i >> m >> r;
  vector<int> a;
  for(int j = 0; ;j++) {
    if(p - i*j <= m) break;
    a.emplace_back(p - i*j);
  }
  int ans = 0, cost = 0;
  for(int x : a) {
    if(cost + x > r) {
      break;
    }
    ans++;
    cost += x;
  }
  if(r - cost > 0) {
    ans += (r - cost) / m;
  }
  cout << ans << '\n';
  return 0;
}
