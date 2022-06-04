#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int nax = 1e4 + 555;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
      cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    map<int, int> mp0, mp1;
    set<int> s0, s1;
    for(int x : a) {
      mp0[x]++;
      s0.insert(x);
    }
    for(int x : b) {
      mp1[x]++;
      s1.insert(x);
    }
    vector<int> ret;
    for(int x : s0) {
      if(mp0[x] == 1) {
        ret.push_back(x);
      }
    }
    for(int x : s1) {
      if(mp1[x] == 1) {
        ret.push_back(x);
      }
    }
    sort(ret.begin(), ret.end());
    map<int, int> mp;
    set<int> s;
    for(int x : ret) {
      mp[x]++;
      s.insert(x);
    }
    for(int x : s) {
      if(mp[x] == 1) {
        cout << x << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
