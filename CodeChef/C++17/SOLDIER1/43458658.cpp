#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> mp;
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    mp[a]++;
  }
  for(auto it : mp) {
    if(it.second >= n/2) {
      cout << it.first << '\n';
      return 0;
    }
  }
}
