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
  int n;
  cin >> n;
  int nxt = 1;
  vector<int> ans;
  set<int> t;
  int s = 0;
  while(1) {
    ans.emplace_back(nxt);
    s += nxt;
    t.insert(nxt);
    nxt++;
    if(s >= n) break;
  }
  int k = ans.size();
  for(int i = k-1; i >= 0; --i) {
    int here = i + 1;
    int b = i*(i+1)/2;
    int rem = n - b;
    if(rem >= here) {
      ans[i] = rem;
      k = i + 1;
      break;
    }
  }
  cout << k << '\n';
  for(int i = 0; i < k; ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
