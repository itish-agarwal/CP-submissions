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
    string s = to_string(n);
    int sum = 0;
    for(char ch : s) {
      sum += ch-'0';
    }
    if(n%sum) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}
