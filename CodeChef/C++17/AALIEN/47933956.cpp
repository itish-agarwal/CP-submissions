#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7; 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> is_prime(N, 1);
  is_prime[1] = 0;

  for(int p = 2; p < N; p++) {
    if(is_prime[p]) {
      for(int j = 2 * p; j < N; j += p)
        is_prime[j] = 0;
    }
  }

  int tests;
  cin >> tests;

  while(tests--) {
    int n, qq;
    cin >> n >> qq;
    int m = n;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> a[i][j];
        a[i][j] = is_prime[a[i][j]];
      }
    }
    const int INF = 2e9 + 7;
    vector<vector<int>> dp(n, vector<int> (m, INF));

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(i == 0 && j == 0) {
          dp[i][j] = a[i][j];
          continue;
        }
        if(i - 1 >= 0)
          dp[i][j] = min(dp[i][j], a[i][j] + dp[i - 1][j]);
        if(j - 1 >= 0)
          dp[i][j] = min(dp[i][j], a[i][j] + dp[i][j - 1]);
      }
    } 
    
    for(int q = 0; q < qq; q++) {
      int x, y;
      cin >> x >> y;
      x -= 1;
      y -= 1;
      cout << dp[x][y] << '\n';
    }

  }
  return 0;

}