#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> suff(n);
  suff.back() = a.back();
  for(int i = n-2; i >= 0; i--) {
    suff[i] = suff[i+1] + a[i];
  }
  long long ans = 0;
  for(int i = 0; i < (n-1); i++) {
    long long x = a[i];
    long long y = suff[i+1];
    x %= mod;
    y %= mod;
    x *= y;
    x %= mod;
    ans += x;
    ans %= mod;
  }
  cout<<ans<<'\n';
  return 0;
}
