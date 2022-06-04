
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
    string s;
    cin >> s;
    int n = s.length();
    if(n % 2) {
      cout << "-1\n";
    } else {
      int cnt = 0;
      for(char ch : s) {
        if(ch == '1') {
          cnt++;
        }
      }
      //cout <<cnt<<endl;
      if(cnt==0 || cnt==n) {
        cout << "-1\n";
      } else {
        cout << abs(n-2*cnt)/2 << '\n';
      }
    }
  }
  return 0;
}
