
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
    int st = 1;
    for(int i = 0; i < n; i++) {
      vector<int> a;
      for(int j = 0; j <= i; j++) {
        a.push_back(st);
        st++;
      }
      for(int i = (int)a.size()-1; i >= 0; i--) {
        cout << a[i];
      }
      cout << '\n';
    }
  }
  return 0;
}
