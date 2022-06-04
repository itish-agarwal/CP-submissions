#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int r = 0, w = 0, ans = 0;
  for(char& ch : s) {
    if(ch == 'W') w++;
    else r++;
  }
  for(int i = 0; i < r; i++) {
    if(s[i] == 'W') ans++;
  }
  cout << ans << '\n';
  return 0;
}
