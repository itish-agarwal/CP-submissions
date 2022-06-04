
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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      int st = n;
      for(int j = 0; j < n-i; j++) {
        cout << " ";
      }
      for(int j = -1; j < i; j++) {
        cout << st;
        --st;
      }
      cout << '\n';
    }
    for(int i = n; i >= 0; i--) {
      cout << i;
    }
    cout << '\n';
    for(int i = 0; i < n; i++) {
      int st = n;
      for(int j = 0; j <= i; j++) {
        cout << " ";
      }
      for(int j = 0; j < n-i; j++) {
        cout << st;
        --st;
      }
      cout << '\n';
    }    
  }
  return 0;
}
