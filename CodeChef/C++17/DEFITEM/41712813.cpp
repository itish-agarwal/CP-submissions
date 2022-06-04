#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> rev;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      rev[a[i]] = i;
    }
    vector<int> pre(n), post(n);
    pre[0] = a[0];
    post[n-1] = a[n-1];
    for(int i = 1; i < n; i++) {
      pre[i] = pre[i-1] + a[i];
    }
    for(int i = n-2; i >= 0; i--) {
      post[i] = post[i+1] + a[i];
    }
    while(q--) {
      int x;
      cin >> x;
      x = rev[x];
      cout << min(pre[x], post[x]) << '\n';
    }
  }
  return 0;
}
    
