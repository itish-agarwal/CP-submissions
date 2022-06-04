#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int nax = 1e5 + 555;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<string> ret;
  for(int i = 1; i < nax; i++) {
    string s = "";
    int t = i;
    while(t) {
      if(t % 2) {
        s += '1';
      } else {
        s += '0';
      }
      t /= 2;
    }
    ret.push_back(s);
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    
    int in = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout<<ret[in] << " ";
        in++;
      }
      cout << '\n';
    }
  }
  return 0;
}
      
    
