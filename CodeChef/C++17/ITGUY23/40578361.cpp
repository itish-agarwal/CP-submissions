
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
  vector<int> ret;
  const int nax = 1e5 + 6;
  for(int i = 1; i <= nax; i++) {
    int t = 0;
    int n = i;
    int p = 0;
    while(n > 0) {
      int d = n%2;
      n /= 2;
      if(d == 1) {
        t += power(6, p);
      }
      p++;
    }
    ret.push_back(t);
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    --n;
    cout << ret[n] << '\n';
  }
  return 0;
}  
    
