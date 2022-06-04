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
    string s, t1, t2;
    cin >> s >> t1 >> t2;
    sort(s.begin(), s.end());
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if(s==t1 && s==t2) {
      cout << "Possible\n";
    } else {
      cout << "Not Possible\n";
    }
  }
}
