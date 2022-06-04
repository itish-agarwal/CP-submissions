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
    bool can = 0;
    if(n%2 == 0) {
      int x = n / 2;
      int s = sqrt(x);
      if(s*s == x) {
        can = 1;
      }
    }
    if(n%4 == 0) {
      int x = n / 4;
      int s = sqrt(x);
      if(s*s == x) {
        can = 1;
      }
    }
    cout << (can ? "YES" : "NO") << '\n';
  }
}