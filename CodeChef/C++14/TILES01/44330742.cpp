#include <bits/stdc++.h>
 
using namespace std;
const int mod = 15746;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int> (2, 0));
  dp[1][1] = dp[2][0] = dp[2][1] = 1;
  for(int i = 3; i <= n; ++i) {
    add_self(dp[i][1], dp[i-1][0] + dp[i-1][1]);
    add_self(dp[i][0], dp[i-2][0] + dp[i-2][1]);
  }
  cout << (dp[n][0] + dp[n][1]) % mod << '\n';
}
