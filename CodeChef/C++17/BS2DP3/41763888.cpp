#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll power(ll a, ll b) {
  if(b==0) return 1;
  ll res = power(a, b/2);
  res = (res * res) % mod;
  if(b % 2) {
    res = (res * a) % mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    ll n;
    cin >> n;
    --n;
    cout << power(2LL, n) << '\n';
  }
  return 0;
}
