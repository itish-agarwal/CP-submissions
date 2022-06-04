
#include <bits/stdc++.h>

using namespace std;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x;
    cin >> n >> x;
    int mx = 0, mn = 1e6;
    while(n--) {
      int y;
      cin >> y;
      mx = max(mx, y);
      mn = min(mn, y);
    }
    if(mx - mn < x) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}