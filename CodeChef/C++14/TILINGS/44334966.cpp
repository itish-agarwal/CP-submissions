#include <bits/stdc++.h>
 
using namespace std;
const int mod = 1e4;

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
  vector<vector<int>> dp(n + 1, vector<int> (4));
  dp[n][0] = dp[n][3] = 1;
  dp[n-1][0] = dp[n-1][3] = 1;
  for(int i = n-2; i >= 0; --i) {
    add_self(dp[i][0], dp[i+1][0]);
    add_self(dp[i][0], dp[i+2][0]);
    add_self(dp[i][0], dp[i+1][2]);
    add_self(dp[i][0], dp[i+1][1]);
    
    add_self(dp[i][1], dp[i+1][2]);
    add_self(dp[i][1], dp[i+2][0]);
    
    add_self(dp[i][2], dp[i+1][1]);
    add_self(dp[i][2], dp[i+2][0]);
    
    add_self(dp[i][3], dp[i+1][0]);
  }
  cout << dp[0][0] << '\n';
}
  
  
