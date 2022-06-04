#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre(n);
    int ans = n + n;
    pre[0] = (s[0] == '1');
    for(int i = 1; i < n; i++ ){
      pre[i] = pre[i-1];
      if(s[i] == '1') {
        pre[i]++;
      }
    }
    ans = min(ans, pre.back());
    ans = min(ans, n - pre.back());
    for(int i = 0; i + 1 < n; i++) {
      //zeros upto i, ones afterwards;
      int pos = pre[i];
      pos += (n-i-1) - (pre.back() - pre[i]);
      ans = min(ans, pos);
    }
    cout << ans << '\n';
  }
  return 0;
}
