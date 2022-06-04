#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
using ll = long long;

bool is7(string s) {
  int x = stoi(s);
  if(x%7) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int ans = is7(s);
    while(next_permutation(s.begin(), s.end())) {
      ans += is7(s);
    }
    cout << ans << '\n';
  }
  return 0;
}
