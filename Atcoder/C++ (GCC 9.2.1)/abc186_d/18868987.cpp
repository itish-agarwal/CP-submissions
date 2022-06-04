
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
  
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  int s = 0;
  for(int x : a) {
    s += x;
  }
  for(int i = 0; i < n; i++) {
    s -= a[i];
    ans += (s - (n-i-1)*a[i]);
  }
  cout << ans << '\n';
  return 0;
}
  
