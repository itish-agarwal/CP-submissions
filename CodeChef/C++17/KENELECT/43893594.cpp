#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int nax = 1e3 + 555;
int fact[nax];
 
int power(int a, int b) {
  if(b == 0) return 1;
  int res = power(a, b/2);
  res = (res * res) % mod;
  if(b % 2) {
    res = (res * a) % mod;
  }
  return res;
} 
void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for(int i = 1; i < nax; i++) {
    fact[i] = ((int)i*fact[i-1]) % mod;
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(n + 1);
    int s = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }    
    sort(a.rbegin(), a.rend());
    int c = a[k-1];
    int cc = 0;
    for(int i = 0; i < k; i++) {
      if(a[i] == c) {
        cc++;
      }
    }
    int p = cnt[c];
    int q = cc;
    q = (fact[q] * fact[p-q]) % mod;
    p = fact[p];
    q = power(q, mod - 2);
    p = (p * q) % mod;
    cout << p << '\n';
  }
  return 0;
}
