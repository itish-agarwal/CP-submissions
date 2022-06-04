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
    if(n==1) {
      cout << "9\n";
    } else if(n==2) {
      cout << "98\n";
    } else {
      string ans = "989";
      n -= 3;
      int nxt = 0;
      while(n--) {
        ans += (char)(nxt+'0');
        nxt++;
        if(nxt > 9) {
          nxt = 0;
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}