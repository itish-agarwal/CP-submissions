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
  
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> rets(n), rete(n);
    for(int i = 0; i < n; i++) {
      cin >> rets[i].first >> rets[i].second;
      rete[i].first = rets[i].second;
      rete[i].second = rets[i].first;
    }
    sort(rets.begin(), rets.end());
    sort(rete.begin(), rete.end());
    
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
      a[i] = rets[i].first;
      b[i] = rete[i].first;
    }      
    int ans = n - 1;
    for(pair<int, int> seg : rets) {
      int l = seg.first;
      int r = seg.second;      
      int in = lower_bound(b.begin(), b.end(), l) - b.begin() - 1;
      int pos = in + 1;      
      in = upper_bound(a.begin(), a.end(), r) - a.begin();      
      pos += n-in;
      ans = min(ans, pos);
    }
    cout << ans << '\n';
  }
  return 0;
}