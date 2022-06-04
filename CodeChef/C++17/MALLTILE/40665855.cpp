
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
  int n, m, a;
  cin >> n >> m >> a;
  int l = n/a;
  if(n % a) ++l;
  int b = m/a;
  if(m % a) b++;
  cout << l*b << '\n';
  return 0;
}
