#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int nax = 1e4 + 555;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    if(n == 1) {
      cout << "*\n";
    } else {
      vector<string> ans;
      string t = "";
      for(int i = 0; i < 2*n-1; i++) {
        t += '*';
      }
      ans.push_back(t);
      int i = 1, j = 2*n-3;
      for(int op = 1; op < n; op++) {
        string s = "";
        for(int j = 0; j < 2*n-1; j++) {
          s += " ";
        }
        s[i] = s[j] = '*';
        ans.push_back(s);
        i++;
        j--;
      }
      for(int i = n-1; i >= 0; i--) {
        cout << ans[i] << '\n';
      }
    }
  }
  return 0;
}
        
    
