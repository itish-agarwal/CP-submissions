
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int still = 120 - n;
    for(char ch : s) {
      if(ch == '1') {
        still++;
      }
    }
    if(still >= 90) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
