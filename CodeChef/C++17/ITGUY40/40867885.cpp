
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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      int mx = n - i;
      if(i % 2) {
        if(mx % 2) {
          for(int j = 1; j <= mx; j++) {
            cout << j;
          }
        } else {
          for(int j = mx; j >= 1; j--) {
            cout << j;
          }
        }          
      } else {
        if(mx % 2) {
          for(int j = 1; j <= mx; j++) {
            cout << j;
          }
        } else {
          for(int j = mx; j >= 1; j--) {
            cout << j;
          }
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
