
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
  int n, m;
  cin >> n >> m;
  int a[n][m];
  int mn = 1e18;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      ans += a[i][j];
      mn = min(mn, a[i][j]);
    }
  }
  ans -= mn*n*m;
  cout << ans << '\n';
  
  return 0;
}
