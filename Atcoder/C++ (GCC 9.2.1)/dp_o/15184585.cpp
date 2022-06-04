#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int> (n));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> dp(n + 1, vector<int> (1 << n, 0));
  //dp[i][mask] is the num of ways to match first i men with set of women represented
  //by mask
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++) {    
    for(int mask = 0; mask < (1 << n); mask++) {
      if(__builtin_popcount(mask) == i) {        
        for(int bit = 0; bit < n; bit++) {
          if((mask&(1 << bit)) && a[i - 1][bit]) {
            add(dp[i][mask], dp[i - 1][mask - pow(2, bit)]);
          }
        }
      }
    }
  }
  cout << dp[n][(1<<n) - 1] << '\n';
  return 0;
}
