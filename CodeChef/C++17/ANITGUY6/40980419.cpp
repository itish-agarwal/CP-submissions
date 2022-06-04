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
    if(n == 1) {
      cout << "*\n";
    } else {
      int sp = -1;
      for(int i = 0; i < n/2; i++) {
        cout << "*";
        if(sp>=0) {
          for(int j = 0; j < sp; j++) {
            cout << " ";
          }
          cout << "*";
        }
        cout << '\n';
        sp++;
      }
      cout << "*";
      for(int j = 0; j < sp; j++) {
        cout << " ";
      }
      cout << "*";
      cout << '\n';
      sp--;
      for(int i = 0; i < n/2; i++) {
        cout << "*";
        if(sp>=0) {
          for(int j = 0; j < sp; j++) {
            cout << " ";
          }
          cout << "*";
        }
        cout << '\n';
        sp--;
      }
    }
  }
  return 0;
}
    
