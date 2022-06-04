#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
      cin >> b[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int i = n-1; i >= 0; i--) {
      for(int j = m-1; j >= 0; j--) {
        if(i==n-1 && j==m-1) {
          dp[i][j] = max(0, max(a[i], max(b[j], a[i] + b[j])));
          continue;
        }
        dp[i][j] = max(0, max(dp[i+1][j] + a[i], dp[i][j+1] + b[j]));
      }
    }
    cout << dp[0][0] << '\n';
  }
  return 0;
}