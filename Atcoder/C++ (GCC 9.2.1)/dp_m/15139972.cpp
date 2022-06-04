#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
void sub(int& a, int b) {
  a -= b;
  if(a < 0) {
    a += mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
  for(int i = 0; i <= n; i++) dp[i][0] = 1;
  for(int j = 1; j <= k; j++) {
    if(j <= a[n - 1]) dp[n - 1][j] = 1;
  }
  for(int i = n - 2; i >= 0; i--) { 
    int ways = 0;
    for(int j = 0; j <= a[i]; j++) {
      add(ways, dp[i + 1][j]);
      dp[i][j] = ways;
    }
    for(int j = a[i] + 1; j <= k; j++) { 
      add(ways, dp[i + 1][j]);
      sub(ways, dp[i + 1][j - a[i] - 1]);
      dp[i][j] = ways;
    }
  }    
  cout << dp[0][k] << '\n';
  return 0;
}
  
 
  
  

