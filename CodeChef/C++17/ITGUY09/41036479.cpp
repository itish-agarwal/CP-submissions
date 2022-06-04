#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    set<int> s0, s1, s;
    map<int, int> mp0, mp1, mp;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
      cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int x : a) {
      s0.insert(x);
      mp0[x]++;
    }
    for(int x : b) {
      s1.insert(x);
      mp1[x]++;
    }
    vector<int> ret;
    for(int x : s0) {
      if(s1.find(x)!=s1.end()) {
        ret.push_back(x);
      }
    }
    sort(ret.begin(), ret.end());
    for(int x : ret) {
      cout << x << " ";
    }
    cout << '\n';
  }
  return 0;
}
