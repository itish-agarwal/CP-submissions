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
void add_self(ll& a, ll b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ll mn = 1e15, mx = -1e15;
  ll x[n], y[n];
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    mn=min(mn, x[i]+y[i]);
    mx=max(mx, x[i]+y[i]);
  }
  ll ans = abs(mx-mn);
  mn = 1e15, mx = -1e15;
  for(int i = 0; i < n; i++) {
    mn=min(mn, x[i]-y[i]);
    mx=max(mx, x[i]-y[i]);
  }
  ans = max(ans, abs(mx-mn));
  mn = 1e15, mx = -1e15;
  for(int i = 0; i < n; i++) {
    mn=min(mn, y[i]-x[i]);
    mx=max(mx, y[i]-x[i]);
  }
  ans = max(ans, abs(mx-mn));
  cout << ans << '\n';
  return 0;
}
