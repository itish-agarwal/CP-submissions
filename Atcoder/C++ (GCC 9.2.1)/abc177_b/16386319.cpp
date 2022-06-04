#include <bits/stdc++.h>

using namespace std;

int diff(string a, string b) {
  int d = 0;
  for(int i = 0; i < (int)a.size(); i++) {
    if(a[i]!=b[i]) d++;
  }
  return d;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int ans = 2e9;
  for(int i = 0; i <= (n-m); i++) {
    string cur = s.substr(i, m);
    ans = min(ans, diff(cur, t));
  }
  cout << ans << '\n';
  return 0;
}
