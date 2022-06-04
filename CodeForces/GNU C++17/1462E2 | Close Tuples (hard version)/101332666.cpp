#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int nax = 2e5 + 666;
const int mod = 1e9 + 7;
vector<int> fact(nax);
 
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
  res %= mod;
  if(b % 2) {
    res *= a;
    res %= mod;
  }
  return res;
}
int ncr(int n, int r) {
  int ans = fact[n];
  int den = fact[r]*fact[n-r];
  den %= mod;
  den = power(den, mod - 2);
  ans *= den;
  return ans % mod;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  fact[0] = 1;
  for(int i = 1; i < nax; i++) {
    fact[i] = (i * fact[i-1]) % mod;
  }
  
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    //sort(a.begin(), a.end());
    sort(a, a + n);
    
    for(int i = n-1; i >= m-1; i--) {
      int x = a[i] - k;
      int in = lower_bound(a, a + i, x) - a;
      if(i-in < m-1) {
        continue;
      }
      int el = i - in;
      ans += ncr(el, m-1);
      ans %= mod;
    }
    cout << ans << '\n';
  }
  return 0;
}