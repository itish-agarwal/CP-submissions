#include <bits/stdc++.h>

using namespace std;
const int nax = 1e5 + 67;
vector<string> dp(nax);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s = to_string(n);
    int ans = 0;
    for(char ch : s) {
      int d = ch - '0';
      if(d>0 && n%d==0) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
