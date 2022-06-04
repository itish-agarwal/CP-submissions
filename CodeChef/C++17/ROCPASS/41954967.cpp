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
    string v = "", t = "";
    for(char ch : s) {
      if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
        v.push_back(ch);
      } else {
        t.push_back(ch);
      }
    }
    sort(v.begin(), v.end());
    cout << v + t << '\n';
  }
  return 0;
}
