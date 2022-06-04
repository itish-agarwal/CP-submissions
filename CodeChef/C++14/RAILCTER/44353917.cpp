#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
const int INF = 2e18 + 7;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> end(n + 2), begin(n + 2), pre(n + 1);
  for(int i = 1; i <= n; ++i) {
    end[i] = a[i] + max(0LL, end[i-1]);
    pre[i] = a[i] + pre[i-1];
  }
  for(int i = n; i >= 1; --i) {
    begin[i] = a[i] + max(0LL, begin[i+1]);
  }
  int ans = -INF;
  for(int i = 1; i <= n-k+1; ++i) {
    int s = pre[i+k-1] - pre[i-1];
    int left_max = max(0LL, end[i-1]);
    int right_max = max(0LL, begin[i+k]);
    //cout << i << " " << s << " " << left_max << " " << right_max << '\n';
    ans = max(ans, s + left_max + right_max);
  }
  cout << ans << '\n';  
}
    
  
