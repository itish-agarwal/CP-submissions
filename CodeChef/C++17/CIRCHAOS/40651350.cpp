
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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt, add;
  cin >> tt;
  while(tt--) {
    int n, m, g = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      int x;
      cin >> x;
      g = __gcd(g, x);
    }
    int mx = 1;
    for(int i = 1; i*i <= g; i++) {
      if(g%i == 0) {
        int d = i;
        if(d <= n) {
          mx = max(mx, d);
        }
        d = g/i;
        if(d <= n) {
          mx = max(mx, d);
        }
      }
    }
    cout << n - mx << '\n';
  }
  return 0;
}
