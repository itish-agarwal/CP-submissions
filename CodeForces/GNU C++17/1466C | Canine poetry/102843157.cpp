#include <bits/stdc++.h>
 
using namespace std;
const int nax = 1e5 + 55;
vector<vector<int>> has(nax), g;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for(int i = 1; i < n; i++) {
      bool x = (s[i]==s[i-1]);
      bool y = false;
      if(i>=2) {
        y = (s[i]==s[i-2]);
      }
      if(x | y) {
        s[i] = '?';
      } 
    }
    for(char ch : s) {
      if(ch == '?') {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
  
  