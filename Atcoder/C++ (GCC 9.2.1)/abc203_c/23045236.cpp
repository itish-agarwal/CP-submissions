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
    int a, b;
    cin >> a >> b;
    ret.emplace_back(a, b);
  }
  sort(ret.begin(), ret.end());

  int max_x = k;
  int i = 0;

  while(i < n && ret[i].first <= max_x) {
    max_x += ret[i].second;
    i++;
  }

  cout << max_x << '\n';
}
