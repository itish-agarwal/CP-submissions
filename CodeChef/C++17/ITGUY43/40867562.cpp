
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
    for(int i = 0; i < n-1; i++) {
      if(i == 0) {
        cout << "*\n";
      } else {
        cout << "*";
        int sp = i-1;
        for(int j = 0; j < sp; j++) {
          cout << " ";
        }
        cout << "*\n";
      }
    }
    for(int i = 0; i < n; i++) {
      cout << "*";
    }
    cout << '\n';
  } 
  return 0;
}
