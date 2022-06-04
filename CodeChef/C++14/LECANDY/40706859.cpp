
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

//ABCDEFGHIJKLMNOPQRSTUVWXYZ

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, C, x, S = 0;
    cin >> n >> C;
    while(n--) {
      cin >> x;
      S += x;
    }
    if(C >= S) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
