#include <bits/stdc++.h>

using namespace std;
//dp[i(th) key][mask]
//0->locked
//1->open
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> cost(M);
  vector<vector<int>> boxes(M);
  for(int i = 0; i < M; i++) {
    cin >> cost[i];
    int b;
    cin >> b;
    while(b--) {
      int box;
      cin >> box;
      box--;
      boxes[i].push_back(box);
    }
  }
  const int inf = 2e9 + 7;
  vector<vector<int>> dp(M + 1, vector<int> ((1 << N) + 1, inf));
  for(int i = M; i >= 0; i--) {
    for(int mask = (1 << N) - 1; mask >= 0; mask--) {
      if(i == M) {
        dp[i][(1 << N)-1] = 0;
        continue;
      }
      dp[i][mask] = dp[i + 1][mask];
      //use this key
      int new_mask = mask;
      for(int b : boxes[i]) {
        new_mask |= (1 << b);
      }
      dp[i][mask] = min(dp[i][mask], cost[i] + dp[i + 1][new_mask]);
    }
  }
  cout << (dp[0][0] >= inf ? -1 : dp[0][0]) << '\n';
}