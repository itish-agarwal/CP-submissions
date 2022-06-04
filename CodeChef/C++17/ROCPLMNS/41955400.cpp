#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    multiset<int> t;
    t.insert(0);
    int sum = 0;
    for(char ch : s) {
      if(ch == '+') sum++;
      else sum--;
      int least = *t.begin();
      ans = max(ans, sum - least);
      t.insert(sum);
    }
    cout << ans << '\n';
  }
  return 0;
}
