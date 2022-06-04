#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void max_self(ll& a, ll b) {
  a = max(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W;
  cin >> n >> W;
  vector<ll> dp(W + 1);
  //dp[i] -> max value with total weight of items exactly i
  for(int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    for(int wt = W - w; wt >= 0; wt--) {
      max_self(dp[wt + w], dp[wt] + v);
    }
  }
  ll answer = 0;
  for(int i = 0; i <= W; i++) {
    answer = max(answer, dp[i]);
  }
  cout << answer << '\n';
  return 0;
}
      
