#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  stack<char> t;
  for(char ch : s) {
    if(t.empty()) {
      t.push(ch);
    } else {
      if(ch == t.top()) {
        t.pop();
      } else {
        t.push(ch);
      }
    }
  }
  string ans = "";
  while(!t.empty()) {
    ans += t.top();
    t.pop();
  }
  if(ans.empty()) {
    cout << "Empty String\n";
  } else {
    
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
  return 0;
}
