#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long 
const int INF = 2e18 + 777;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> ret(n);
    for(int i = 0; i < n; ++i) {
      cin >> ret[i].first >> ret[i].second;
    }
    sort(ret.begin(), ret.end());
    int answer = INF;
    for(int i = 0; i < n; ++i) {
      int j = i;
      int s = 0;
      while(j<n && s<m) {
        s += ret[j].second;
        ++j;
      }
      if(s >= m) {
        answer = min(answer, ret[j-1].first - ret[i].first);
      }
    }
    cout << answer << '\n';
  }
}
