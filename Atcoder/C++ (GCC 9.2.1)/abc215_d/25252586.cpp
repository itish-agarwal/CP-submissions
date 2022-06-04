#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 2e18 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  vector<pair<int, int>> points;
  for(int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    points.emplace_back(x, y);
  }

  sort(points.begin(), points.end());

  vector<int> X, preffix_max(N, points[0].second), preffix_min(N, points[0].second);

  for(auto p : points)
    X.emplace_back(p.first);

  for(int i = 1; i < N; ++i) {
    preffix_max[i] = max(preffix_max[i-1], points[i].second);
    preffix_min[i] = min(preffix_min[i-1], points[i].second);
  }

  int lo = 0, hi = INF, ans = 0;

  while(lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    bool ok = false;

    for(int i = 0; i < N; ++i) {
      int in = upper_bound(X.begin(), X.end(), X[i] - mid) - X.begin() - 1;
      if(in >= 0) {
        int min_Y = preffix_min[in], max_Y = preffix_max[in];
        if(min_Y <= points[i].second - mid || max_Y >= points[i].second + mid) {
          ok = true;
          break;
        }
      }
    }

    if(ok == true) {
      lo = mid + 1;
      ans = mid;
    }

    else {
      hi = mid - 1;
    }
  }

  cout << ans << '\n';
}