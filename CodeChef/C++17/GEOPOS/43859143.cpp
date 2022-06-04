#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
    vector<int> a(n);
    for(auto& it : a) cin >> it;
    sort(a.begin(), a.end());
    if(n <= 2) {
      cout << "No\n";
      continue;
    } 
    int s = 0;
    for(int i = 0; i + 1 < n; ++i) {
      s += a[i];
    }
    if(s > a.back()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
