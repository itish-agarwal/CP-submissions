#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), pref(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int state = a[i];
    if(pref[i] % 2) {
      state ^= 1;
    }
    if(state == 0) {
      ans++;
      if(i+1<n) {
        pref[i+1] = pref[i]+1;
      }
    } else {
      if(i+1<n) {
        pref[i+1] = pref[i];
      }
    }
  }
  cout << ans << '\n';
}