#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long
const int nax = 1e5 + 999999;
vector<bool> ispr(nax, 1);
vector<int> pr;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ispr[1] = 0;
  for(int p = 2; p*p < nax; p++) {
    if(ispr[p]) {
      for(int i = p+p; i < nax; i += p) {
        ispr[i] = 0;
      }
    }
  }
  for(int i = 2; i < nax; i++) {
    if(ispr[i]) {
      pr.emplace_back(i);
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for(int x : a) {    
    int in = lower_bound(pr.begin(), pr.end(), x) - pr.begin();
    int pos = pr[in] - x;
    in = upper_bound(pr.begin(), pr.end(), x) - pr.begin() - 1;
    if(in>=0) {
      pos = min(pos, x - pr[in]);
    }
    ans += pos;
  }
  cout << ans << '\n';
  return 0;
}
    
