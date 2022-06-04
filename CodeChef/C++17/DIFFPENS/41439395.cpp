#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, l = 1;
    for(int i = 1; i < n; i++) {
      if(s[i]==s[i-1]) {
        ++l;
      } else {
        ans += l-1;
        l = 1;
      }
    }
    ans += l-1;
    cout << ans << '\n';
  }
  return 0;
}
