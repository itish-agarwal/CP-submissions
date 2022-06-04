
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
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for(int i = 0; i < n; i++) {
      for(int x : a) {
        cout << x;
      }
      cout << '\n';
      int st = a[0];
      for(int i = 1; i < n; i++) {
        a[i-1] = a[i];
      }
      a[n-1] = st;
    }
  }
  return 0;
}
