#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for(int i = 0; i < (int)s.size(); ++i) {
    if(i%2) {
      if(s[i]>='a' && s[i]<='z') {
        cout << "No\n";
        return 0;
      }
    } else {
      if(s[i]>='A' && s[i]<='Z') {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
}
