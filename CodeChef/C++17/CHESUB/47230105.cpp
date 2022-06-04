#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int inf = 2e15 + 6;
const int nax = 1e5 + 6;

int N, K, A[nax], pref[nax], preffix_max[nax];

int dp[nax][101][2], vis[nax][101][2];

int rec(int i, int j, int taken) {
  if(i == 0) {
    if(j == 1) {
      return A[0];
    } 
    return -inf;
  }
  if(j == 1) {
    return preffix_max[i];
  }
  if(vis[i][j][taken]) {
    return dp[i][j][taken];
  }
  int ans = -inf;
  if(taken) {
    ans = max(ans, rec(i - 1, j - 1, 0));
  } else {
    ans = max(ans, rec(i - 1, j, 0));
  }
  ans = max(ans, A[i] * j + rec(i - 1, j, 1));
  ans = max(ans, A[i] * j + rec(i - 1, j - 1, 0));
  vis[i][j][taken] = 1;
  return dp[i][j][taken] = ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
    }
    int ll[N];
    ll[0] = A[0];
    for(int i = 1; i < N; i++) {
      ll[i] = A[i] + max(0LL, ll[i - 1]);
    }
    preffix_max[0] = ll[0];
    for(int i = 1; i < N; i++) {
      preffix_max[i] = max(preffix_max[i - 1], ll[i]);
    }
    //memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= N; i++) {
      for(int j = 0; j <=   K; j++) {
        vis[i][j][0] = vis[i][j][1] = 0;
      }
    }
    int ans = -inf;
    for(int i = 0; i < N; i++) {
      ans = max(ans, rec(i, K, 0));
    }
    vector<vector<int>> dp(N, vector<int> (K + 1));
    for(int i = 0; i < N; i++) {
      for(int j = 0; j <= K; j++) {
        dp[i][j] = rec(i, j, 0);
      }
    }
    cout << ans << '\n';
  }
}
