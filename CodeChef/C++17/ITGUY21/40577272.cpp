
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
const int inf = 1e18 + 424252434;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int nax = 100;
  vector<int> fib(nax, 0);
  fib[1] = 1;
  for(int i = 2; i < nax; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= i; j++) {
        cout << fib[j];
      }
      cout << '\n';
    }
  }
  return 0;
}
