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
    for(int i = 0; i < n; i++) {
      int p = 1;
      for(int j = 0; j < n; j++) {
        cout << p;
        p = 1 - p;
      }
      cout << '\n';
    }
  }
  return 0;
}
