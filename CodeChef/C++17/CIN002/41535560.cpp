#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int limit = 1e6 + 6666677;
const ll nax = 1e12 + 23456;
vector<bool> isprime(limit, 1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  isprime[1] = 0;
  for(int p = 2; p*p < limit; p++) {
    if(isprime[p]) {
      for(int i = p + p; i < limit; i += p) {
        isprime[i] = 0;
      }
    }
  }
  set<ll> s;
  for(int i = 2; i < limit; i++) {
    if(isprime[i]) {
      s.insert((ll)i*(ll)i);
    }
  }
  int n;
  cin >> n;
  while(n--) {
    ll x;
    cin >> x;
    if(s.find(x)!=s.end()) {
      cout << "YES ";
    } else {
      cout << "NO ";
    }
  }
  cout << '\n';
  return 0;
}
