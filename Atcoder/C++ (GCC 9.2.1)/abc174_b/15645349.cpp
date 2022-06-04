#include <bits/stdc++.h>

using namespace std;
using ll = long long;
map<ll, ll> mods;

long long mod(ll a, ll b, ll k) {
  //return (a^b)%k
  if(b==0) return 1;
  ll res = mod(a, b/2, k);
  res *= res;
  res %= k;
  if(b & 1) {
    res *= a;
    res %= k;
  }
  return res;
}

int main() {
  long long k;
  scanf("%lld", &k);
  if(k==1 || k==7) {
    printf("1\n");
    return 0;
  }
  if(k%7==0) k /= 7;
  k *= 9;
  set<ll> check;
  ll ans = 1;
  while(1) {
    ll now = mod(10LL, ans, k);
    if(now == 1) {
      printf("%lld\n", ans);
      return 0;
    }
    if(check.find(now) == check.end()) {
      check.insert(now);
    } else {
      printf("-1\n");
      return 0;
    }
    ans++;
  }
}
