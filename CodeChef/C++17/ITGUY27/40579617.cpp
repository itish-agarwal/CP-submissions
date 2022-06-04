
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

const int nax = 1e5 + 666;
vector<bool> ispr(nax, 1);

bool can(int n, int k) {
  if(n < 2*k) {
    return false;
  }
  if(k == 1) {
    return ispr[n];
  }
  if(k == 2) {
    if(n % 2 == 0) {
      return 1;
    }
    return ispr[n-2];
  }
  return 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ispr[1] = 0;
  for(int p = 2; p*p < nax; p++) {
    if(ispr[p]) {
      for(int i = p+p; i < nax; i += p) {
        ispr[i] = 0;
      }
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    cout << can(n, k) << '\n';
  }
  return 0;
}
    
