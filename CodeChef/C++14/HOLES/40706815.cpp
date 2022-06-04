
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

int one(char ch) {
  return ch=='A' || ch=='D' || ch=='O' || ch=='P' || ch=='R' || ch=='Q';
}
int two(char ch) {
  return ch=='B';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int ans = 0;
    for(char ch : s) {
      if(one(ch)) {
        ans++;
      } else if(two(ch)) {
        ans += 2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}  
  
