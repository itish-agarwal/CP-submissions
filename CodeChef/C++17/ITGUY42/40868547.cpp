
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
    int st = -1;
    int sp = n;
    for(int i = 0; i < n; i++) {
      st += 2;
      sp--;
      for(int j = 0; j < sp; j++) {
        cout << " ";
      }
      for(int j = 0; j < st; j++) {
        cout << "*";
      }
      for(int j = 0; j < sp; j++) {
        cout << " ";
      }
      cout << '\n';
      for(int j = 0; j < sp; j++) {
        cout << " ";
      }
      for(int j = 0; j < st; j++) {
        cout << "*";
      }
      for(int j = 0; j < sp; j++) {
        cout << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
