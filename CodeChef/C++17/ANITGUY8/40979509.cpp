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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    set<int> s;
    for(int& x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    for(int x : a) {
      mp[x]++;
      s.insert(x);
    }
    for(int x : s) {
      if(mp[x] > 1) {
        cout << x << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
