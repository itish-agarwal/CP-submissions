#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ans = 1;
  cin >> n;
  vector<int> a(n), dp(n, 1);
  for(auto& it : a) cin >> it;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < i; ++j) {
      if(a[i]%a[j] == 0) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
}
