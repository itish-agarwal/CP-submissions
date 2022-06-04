#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

void add_self(ll& a, ll b) {
  a = (a + b)%mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    ll L, R;
    cin >> L >> R;
    ll answer = 0;
    for(ll bit = 0; bit <= 59; bit++) {
      if(L & (1LL<<bit)) {
        ll K = L + (1LL<<bit) - (L&((1LL<<bit)-1));
        ll times = min(K - L, R - L + 1);
        add_self(answer, (((1LL<<bit)%mod)*(times%mod))%mod);
      }
    }
    cout << answer << '\n';
  }
  return 0;
}
