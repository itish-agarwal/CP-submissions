#include <bits/stdc++.h>

using namespace std;
#define int long long
long long INF = 2e17 + 6;

struct Line {
  long long m, c;
  Line() {}
  Line(long long M, long long C) {
    m = M;
    c = C;
  }
  bool operator<(const Line& p) const {
    return m > p.m || (m == p.m && c > p.c);
  }
  friend double cross(const Line O, const Line A, const Line B) {
    return (A.m - O.m) * 1.d * (B.c - O.c) - (B.m - O.m) * 1.d * (A.c - O.c);
  }
};
struct CHT {
  vector<Line> at;
  CHT() {
    at.clear();
  }
  void add(const Line X) {
    int n = at.size();
    while(n >= 2 && cross(at[n - 2], at[n - 1], X) >= 0.) 
      n -= 1;
    at.resize(n);
    at.push_back(X);
  }
  long long value_at(int mid, int x) {
    return at[mid].m * x + at[mid].c;
  }
  long long min(int x) {
    if(at.empty())
      return INF;
    int lo = 0, hi = (int)at.size() - 1;
    while(lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if(value_at(mid, x) > value_at(mid + 1, x))
        lo = mid + 1;
      else 
        hi = mid;
    }
    return value_at(lo, x);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, C;
  cin >> N >> C;
  vector<long long> h(N);
  for(int i = 0; i < N; i++)
    cin >> h[i];

  vector<int> dp(N);
  CHT cht;
  cht.add(Line(-2 * h[0], h[0] * h[0]));

  for(int i = 1; i < N; i++) {
    dp[i] = cht.min(h[i]) + h[i] * h[i] + C;
    cht.add(Line(-2 * h[i], dp[i] + h[i] * h[i]));
  }
  cout << dp[N - 1] << '\n';
  return 0;
}