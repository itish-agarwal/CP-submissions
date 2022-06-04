#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> ret;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ret.emplace_back(a, a + k - 1);
  }
  sort(ret.begin(), ret.end());

  int ans = 0;
  int i = 0;
  while(i<n) {
    int max_end = ret[i].second;
    int j = i;
    while(j+1<n && ret[j+1].first<=max_end) {
      j++;
      max_end = max(max_end, ret[j].second);
    }
    // cout << ret[i].first << " " << max_end << endl;
    ans += max_end - ret[i].first + 1;
    i = j + 1;
  }

  cout << ans << '\n';
}