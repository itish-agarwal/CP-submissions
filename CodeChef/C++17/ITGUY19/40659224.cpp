
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
  const int nax = 1e5 + 555;
  int tt;
  cin >> tt;
  while(tt--) {
    vector<int> cnt(nax);
    int n, ans = 0;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << '\n';
  }
  return 0;
}
