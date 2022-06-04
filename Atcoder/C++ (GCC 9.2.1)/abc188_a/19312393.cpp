#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  //cin >> tt;
  while(tt--) {
    int x, y;
    cin >> x >> y;
    int a=min(x, y);
    int b = max(x, y);
    if(a+3 > b) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
