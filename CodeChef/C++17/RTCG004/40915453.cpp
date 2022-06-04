#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int n = s.size();
    int i = 0, j = n-1, res = 0;
    while(i < j) {
      res += abs(s[i] - s[j]);
      i++;
      j--;
    }
    cout << res << '\n';
  }
  return 0;
}
