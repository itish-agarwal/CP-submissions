
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

int upto(int n) {
  int mod = n%4;
  if(mod == 0) {
    return n;
  }
  if(mod == 1) {
    return 1;
  }
  if(mod == 2) {
    return n+1;
  }
  return 0;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int L, R;
    cin >> L >> R;
    //cout << upto(R) << " " << upto(L-1) << endl;
    cout << (upto(R)^(L>=1 ? upto(L-1) : 0)) << '\n';
  }
  return 0;
}
