
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
int power(int a, int b) {
  if(b == 0) {
    return 1;
  }
  int res = power(a, b/2);
  res *= res;
  if(b % 2) {
    res *= a;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, L, R;
    cin >> n >> L >> R;
    int mn = n-L, p = 1;
    for(int i = 0; i < L; i++) {
      mn += p;
      p *= 2;
    }
    int mx = 0;
    p = 1;
    for(int i = 0; i < R; i++) {
      mx += p;
      p *= 2;
    }
    p /= 2;
    for(int i = 0; i < (n-R); i++) {
      mx += p;
    }
    cout << mn << " " << mx << '\n';
  }
  return 0;
}
