#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18 + 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> pre(n);  
  for(int i = 0; i < n; i++) cin >> a[i];
  pre[0] = a[0];
  for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];  
  vector<vector<ll>> dp(n, vector<ll> (n, inf));
  for(int L = n - 1; L >= 0; L--) {
    for(int R = L; R < n; R++) {
      if(L == R) dp[L][R] = 0;
      else if(R == L + 1) dp[L][R] = a[L] + a[R];
      else {
        ll sum = pre[R] - (L == 0 ? 0 : pre[L - 1]);
        int ff = R - L + 1;
        for(int len = 1; len < ff; len++) {          
          dp[L][R] = min(dp[L][R], dp[L][L + len - 1] + dp[L + len][R] + sum);               
        }
      }
    }
  }  
  cout << dp[0][n - 1] << '\n';
  return 0;
}
