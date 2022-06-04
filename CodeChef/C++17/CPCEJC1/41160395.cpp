#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    if(k < n) {
      cout << "NO\n";
    } else {
      if(k%n == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
