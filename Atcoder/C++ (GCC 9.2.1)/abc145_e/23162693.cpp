#include <bits/stdc++.h>

using namespace std;
int N, T, A[3005], B[3005];
int dp[3005][3005][2];

int rec(int i, int t, int ordered) {
  if(i == N || t >= T) {
    return 0;
  }
  if(dp[i][t][ordered] > -1) {
    return dp[i][t][ordered];
  }
  int ans = rec(i + 1, t, ordered);
  if(ordered) {
    if(t < T) {
      ans = max(ans, B[i] + rec(i + 1, t + A[i], 1));
    }
  } else {
    ans = max(ans, B[i] + rec(i + 1, A[i], 1));
  }
  return dp[i][t][ordered] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> T;
  vector<pair<int, int>> ret;
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    ret.emplace_back(A[i], B[i]);
  }
  sort(ret.begin(), ret.end());
  for(int i = 0; i < N; i++) {
    A[i] = ret[i].first;
    B[i] = ret[i].second;
  }
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0, 0) << '\n';
}