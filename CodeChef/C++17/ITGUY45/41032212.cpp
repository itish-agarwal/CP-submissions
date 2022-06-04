#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    if(n == 1) {
      cout << "*\n";
    } else {
      int sp = 0;
      for(int i = 0; i < (n+1)/2; i++) {
        for(int j = 0; j < sp; j++) {
          cout << " ";
        }
        cout << "*\n";
        sp++;
      }
      sp -= 2;
      for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < sp; j++) {
          cout << " ";
        }
        cout << "*\n";
        sp--;
      }
    }
  }
  return 0;
}
