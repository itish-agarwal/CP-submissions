#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll power(ll a, ll b) {
  if(b==0) return 1;
  ll res = power(a, b/2);
  res *= res;
  res %= mod;
  if(b&1) {
    res *= a;
    res %= mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  if(n==1) {
    cout << "0\n";
    return 0;
  }
  ll ans = power(10LL, n);
  ans -= 2*power(9LL, n);
  ans = (ans+mod*mod)%mod;
  ans += power(8LL, n);
  ans %= mod;
  cout << ans << '\n';
  return 0;
}
