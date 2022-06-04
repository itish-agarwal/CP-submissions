#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int nax = 1e6 + 7;
vector<int> lps(nax);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  iota(lps.begin(), lps.end(), 0);
  for(int i = 2; i < nax; i++) {
    if(lps[i] == i) {
      for(int j = i + i ; j < nax; j += i) {
        lps[j] = i;
      }
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    map<int, int> mp;
    while(n > 1) {
      int p = lps[n];
      int ti = 0;
      while(n%p == 0) {
        n /= p;
        ti++;
      }
      mp[p] = ti;
    }
    int mx = -1;
    for(auto it : mp) {
      mx = max(mx, it.second);
    }
    int ans = 1;
    for(auto it : mp) {
      if(it.second == mx) {
        ans *= it.first;
      }
    }
    cout << ans << '\n';
  }
}