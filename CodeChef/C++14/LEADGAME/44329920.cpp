#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int mx = -1, ans = 0;
  int p0 = 0, p1 = 0;
  while(n--) {
    int s, t;
    cin >> s >> t;
    p0 += s;
    p1 += t;
    int diff = max(p0, p1) - min(p0, p1);
    if(diff > mx) {
      mx = diff;
      if(p0 >= p1) {
        ans = 0;
      } else {
        ans = 1;
      }
    }
  }
  cout << ans + 1 << " " << mx << '\n';
}
