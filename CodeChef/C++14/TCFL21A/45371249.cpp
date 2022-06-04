#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int k, m;
    cin >> k >> m;
    vector<int> x(k + 1), y(k + 1);
    for(int i = 1; i <= k; i++) cin >> x[i];
    for(int i = 1; i <= k; i++) cin >> y[i];

    int steps = 0;
    for(int i = 1; i <= k; i++) {
      steps += abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
    }
    if(steps < m) {
    // ips <= m) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}