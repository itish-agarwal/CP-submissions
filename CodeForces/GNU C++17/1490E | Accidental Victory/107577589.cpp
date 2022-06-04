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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> ret;
    vector<int> ans;
    for(int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ret.emplace_back(x, i);
    }
    int s = 0;
    sort(ret.begin(), ret.end());
    vector<int> a;
    for(auto it : ret) {
      a.emplace_back(it.first);
    }
    vector<int> pre;
    pre.push_back(a[0]);
    for(int i = 1; i < n; ++i) {
      pre.push_back(pre[i-1] + a[i]);
    }
    vector<bool> can(n, 0);
    can[n-1] = 1;
    for(int i = n-2; i >= 0; --i) {
      int s = pre[i];
      //cout << i << " " << s << '\n';
      if(s >= ret[i+1].first && can[i+1]) {
        can[i] = 1;
      }
    }
    for(int i = 0; i < n; ++i) {
      if(can[i]) {
        ans.push_back(ret[i].second + 1);
      }
    }
    cout << (int)ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
}      