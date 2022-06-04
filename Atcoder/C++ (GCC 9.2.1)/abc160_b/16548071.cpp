#include <bits/stdc++.h>

using namespace std;
#define int long long
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = k;
  for(int i = 1; i < n; i++) {
    ans = min(ans, k - (a[i]-a[i-1]));
  }
  ans = min(ans, a[n-1] - a[0]);
  cout<<ans<<'\n';
  return 0;
}
  
