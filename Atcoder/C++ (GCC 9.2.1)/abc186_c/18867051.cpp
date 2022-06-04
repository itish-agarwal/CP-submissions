
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
  
  int ans = 0;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    bool ok = true;
    int p = i;
    while(p > 0) {
      if(p%10==7) {
        ok = false;
        break;
      }
      p /= 10;
    }
    p = i;
    while(p > 0) {
      if(p%8==7) {
        ok = false;
        break;
      }
      p /= 8;
    }
    ans += ok;
  }
  cout << ans << '\n';
  return 0;
}
  
  
