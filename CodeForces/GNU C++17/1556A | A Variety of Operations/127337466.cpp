#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int c, d;
    cin >> c >> d;
    if(c == 0 && d == 0) {
      cout << 0 << '\n';
    }
    else {
      if((c + d) % 2) {
        cout << -1 << '\n';
      }
      else {
        if(c == d) {
          cout << 1 << '\n';
        }
        else {
          cout << 2 << '\n';
        }
      }
    }
  }
}