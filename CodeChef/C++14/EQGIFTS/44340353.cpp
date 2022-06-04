#include <bits/stdc++.h>
 
using namespace std;

const int nax = 155;
int s, n, a[nax], b[nax];
int dp[nax][45002];

int rec(int i, int x) {
  if(dp[i][x] > -1) {
    return dp[i][x];
  }
  if(i == n) {
    dp[i][x] = abs(s-2*x);
    return dp[i][x];
  }
  dp[i][x] = min(rec(i+1, x+a[i]), rec(i+1,  x+b[i]));
  return dp[i][x];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    s += a[i] + b[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << '\n';
}
  
