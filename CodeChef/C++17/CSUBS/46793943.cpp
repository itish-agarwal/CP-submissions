#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> ret(k);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        ret[i%k].push_back(a[i]);
    }
  
    int ans = 0;

    for(int i = 0; i < k; ++i) {
      int most = 0;
      map<int, int> mp;
      for(int x : ret[i]) {
        mp[x]++;
        most = max(most, mp[x]);
      }
      for(auto it : mp) {
        most = max(most, it.second);
      }

      ans += (int)ret[i].size() - most;
    }
    cout << ans << '\n';
  }
}