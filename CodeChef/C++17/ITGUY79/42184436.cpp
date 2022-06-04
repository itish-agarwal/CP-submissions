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
    int t = n - 1;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j <= i; j++) {
        cout << j+1;
      }
      for(int j = 0; j < t; ++j) {
        cout << "*";
      }
      cout << '\n';
      t--;
    }
  }
}
