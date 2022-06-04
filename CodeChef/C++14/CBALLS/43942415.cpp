#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
const int INF = 2e9 + 77;
const int nax = 1e4 + 7;
vector<int> pr(nax, 1);

int ceil(int a, int b) {
  return (a + b - 1)/b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  pr[1] = 0;
  vector<int> primes;
  for(int p = 2; p*p < nax; ++p) {
    if(pr[p]) {
      for(int i = p+p; i < nax; i += p) {
        pr[i] = false;
      }
    }
  }  
  for(int i = 2; i < nax; ++i) {
    if(pr[i]) {
      primes.push_back(i);
    }
  }  
  int tt;
  cin >> tt;
  while(tt--) {
  	int n;
    cin >> n;
    vector<int> a(n);
    for(auto& it : a) cin >> it;
    int ans = INF;
    for(int p : primes) {
      int pos = 0;
      vector<int> b(n);
      b[0] = ceil(a[0], p) * p;
      for(int i = 1; i < n; ++i) {
        int maybe = ceil(a[i], p) * p;
        if(maybe <= b[i-1]) {
          b[i] = b[i-1];
        } else {
          b[i] = maybe;
        }
      }
      for(int i = 0; i < n; ++i) {
        pos += b[i] - a[i];
      }
      ans = min(ans, pos);
    }
    cout << ans << '\n';
  }
}
