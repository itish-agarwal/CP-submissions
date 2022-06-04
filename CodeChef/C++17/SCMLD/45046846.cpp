#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; ++j) {
        char ch ;
        cin >> ch;
        if(ch == 'W') g[i][j] = 1;
      }
    }
    int answer = 0;
    vector<vector<int>> dp(n, vector<int> (n, 1));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; ++j) {
        if(i == 0 || j == 0) {
          answer += dp[i][j];
          continue;
        }
        if(g[i][j]!=g[i-1][j] && g[i][j]!=g[i][j-1] && g[i][j]==g[i-1][j-1]) {
          int mn = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
          dp[i][j] = mn + 1;
        }
        answer += dp[i][j];
      }
    }
    cout << answer << '\n';
  }
}