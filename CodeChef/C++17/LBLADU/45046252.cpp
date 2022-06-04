#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int nax = 1e3 + 7;
vector<int> is_prime(nax, 1);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  is_prime[1] = 0;
  for(int i = 2; i < nax; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j < nax; j += i) {
        is_prime[j] = 0;
      }
    }
  }
  vector<int> primes;
  for(int i = 2; i < nax; i++) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, a;
    cin >> n >> m;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
      cin >> a;
      for(auto p : primes) {
        if(a%p == 0) {
          mp[p]++;
        }
      }
    }
    while(m--) {
      int pr;
      cin >> pr;
      int div = mp[pr];
      int answer = div * (n - 1);
      answer -= div * (div - 1) / 2;
      cout << answer << " " ;
    }
    cout << '\n';
  }
}