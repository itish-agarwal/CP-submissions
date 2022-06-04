#include <bits/stdc++.h>

using namespace std;
#define int long long 

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

int ncr(int n, int r) {
  if(r==0 || r==n) {
    return 1;
  }
  int ans = ncr(n-1, r-1);
  ans *= n;
  return ans/r;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int l;
  cin >> l;
  //(l-1)C11
  cout << ncr(l-1, 11LL) << '\n';
  return 0;
}
  
  
