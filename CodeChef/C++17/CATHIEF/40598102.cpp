
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
  int tt;
  cin >> tt;
  
  while(tt--) {
    int x, y, k, n;
    cin >> x >> y >> k >> n;
    k += k;
    if(abs(x-y) % k) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}
