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
    int s = 1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << s;
        s += 2;
      }
      cout << '\n';
    }
  }      
  return 0;
}
