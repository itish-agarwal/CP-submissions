#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> cnt(10);
  for(int i = 0; i < 26; ++i) {
    cnt[i%10] ++;
  }
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int ans = 1;
    for(int i = 0; i < 10; ++i) {
      ans *= cnt[s[i]-'0'];
    }
    cout << ans << '\n';
  }
}
          
