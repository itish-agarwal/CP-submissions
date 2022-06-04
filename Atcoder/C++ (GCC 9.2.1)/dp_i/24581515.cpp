#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
ll mod = 1e9 + 7;
 
int main() {
  ios_base::sync_with_stdio(0);   //false
  cin.tie(0); //NULL
  cout.tie(0); //NULL
 
  int n;
  cin >> n;
  vector<long double> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  vector<vector<long double>> dp(n + 1, vector<long double>(n + 1, 0.0));
  dp[0][0] = 1.0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j)  dp[i][j] = p[i - 1] * dp[i - 1][j - 1];
      dp[i][j] += (1 - p[i - 1]) * dp[i - 1][j];
    }
  }
  long double ans = 0.0;
  for (int i = n / 2 + 1; i <= n; i++)
    ans += dp[n][i];
  printf("%.12Lf\n", ans);
  return 0;
 
}