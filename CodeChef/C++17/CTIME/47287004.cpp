#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N, K, F, most = 0;;
    cin >> N >> K >> F;
    vector<pair<int, int>> intervals;
    for(int i = 0; i < N; i++) {
      int S, T;
      cin >> S >> T;
      most = max(most, T);
      intervals.emplace_back(S, T);
    }
    sort(intervals.begin(), intervals.end());
    int i = 0, got = 0;
    while(i < N) {
      int max_end = intervals[i].second;
      int j = i;
      while(j + 1 < N && intervals[j + 1].first <= max_end) {
        j++;
        max_end = max(max_end, intervals[j].second);
      }
      if(j + 1 < N) {
        got += intervals[j + 1].first - max_end;
      }
      i = j + 1;
    }
    got += intervals[0].first;
    got += F - most;
    cout << (got >= K ? "YES\n" : "NO\n");
  }
}
