#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 2e18 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, N;
  cin >> n;
  N = 3 * n;
  vector<int> P(N);
  for(auto& a : P)
    cin >> a;

  multiset<int> s, beg;
  int sum = 0;
  for(int i = N - 1; N - i <= N / 3; i--) {
    s.insert(P[i]);
    sum += P[i];
  }

  vector<int> suffix_minimum(N, INF);
  suffix_minimum[N - N/3] = sum;

  for(int i = N - N / 3 - 1; i >= 0; i--) {
    int cur_max = *s.rbegin();
    if(P[i] < cur_max) {
      sum -= cur_max;
      sum += P[i];
      s.erase(s.find(cur_max));
      s.insert(P[i]);
    }
    suffix_minimum[i] = sum;
  }

  int sum2 = 0, ans = -INF;
  for(int i = 0; i < N - N / 3 - 1; i++) {
    if(i < N / 3) {
      sum2 += P[i];
      beg.insert(P[i]);
      if(i == N / 3 - 1) {
        ans = max(ans, sum2 - suffix_minimum[i + 1]);
      }
    } else {
      int cur_min = *beg.begin();
      if(P[i] > cur_min) {
        sum2 -= cur_min;
        sum2 += P[i];
        beg.erase(beg.find(cur_min));
        beg.insert(P[i]);
      }
      ans = max(ans, sum2 - suffix_minimum[i + 1]);
    }
  }

  cout << ans << '\n';
  return 0;
}