#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long
const int inf = 2e18 + 555;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  vector<int> in{-1};
  int n = s.size();
  //cout << n << '\n';
  for(int i = 0; i < n; i++) {
    if(s[i] == ' ') {
      in.push_back(i);
    }
  }
  cout << n - in.back() - 1 << '\n';
  return 0;
}
