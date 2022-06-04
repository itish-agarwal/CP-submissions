#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  int ans = n + n;
  int sum = 0;
  for(char ch : s) {
    sum += ch - '0';
  }
  for(int mask = 0; mask < (1<<n); mask++) {
    int remove = 0, pos = 0;
    for(int bit = 0; bit < n; bit++) {
      if((mask>>bit) & 1) {
        pos++;
        remove += s[bit]-'0';
      }
    }
    if((sum-remove)%3 == 0) {
      ans = min(ans, pos);
    }
  }
  if(ans == n) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}
