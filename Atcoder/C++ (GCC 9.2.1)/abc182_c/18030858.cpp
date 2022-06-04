#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int&x : a) {
    cin >> x;
  }
  int gn = 0, ans;
  for(int can = 2; can <= 1050; can++) {
    int here = 0;
    for(int x : a) {
      if(x%can == 0) {
        here++;
      }
    }
    if(here > gn) {
      gn = here;
      ans = can;
    }
  }
  cout << ans << '\n';
  return 0;
}
