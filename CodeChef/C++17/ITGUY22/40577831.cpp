
#include <bits/stdc++.h>

using namespace std;
#define int int64_t 

ostream& operator << (ostream& stream, const vector<int>& v) {
  for(int x : v) {
    stream << x << " ";
  }
  return stream;
}

//ostream& operator << (ostream& stream, const int *a) {
  //for(int i = 0; i < n; i++) {
    //stream << *(a + i) <<  " ";
  //}
  //return stream;
//}
const int inf = 1e18 + 424252434;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x, y;
    cin >> x >> y;
    int lcm = (x*y)/__gcd(x, y);
    int ans = lcm/x + lcm/y - 2;
    //if(x == y) ans = 0;
    cout << ans << '\n';
  }
  return 0;
}
