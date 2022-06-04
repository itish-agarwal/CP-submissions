
#include <bits/stdc++.h>

using namespace std;
#define int int64_t 
const int nax = 1e3 + 44;

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
  int n;
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    int e = 0, o = 0;
    for(char ch : s) {
      int d = ch - '0';
      if(d % 2) {
        o += d;
      } else {
        e += d;
      }
    }
    if(e%4==0 || o%3==0) {
      cout << "Yes ";
    } else {
      cout << "No ";
    }
  }
  cout << '\n';
  return 0;
}
