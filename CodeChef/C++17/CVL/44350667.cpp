#include <bits/stdc++.h>
 
using namespace std;
#define int long long 

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, T;
  cin >> n >> T;
  vector<int> a(n);
  int s = 0, mn = 1e10 + 7;
  for(auto& it : a) {
    cin >> it;
    s += it;
    mn = min(mn, it);
  }
  int ans = (T / s) * n;
  int rem = T % s;
  int nxt = 0;
  while(rem >= mn) {
    if(rem >= a[nxt]) {
      ans++;
      rem -= a[nxt];
    }
    nxt = (nxt + 1) % n;
  }
  cout << ans << '\n';
}
    
