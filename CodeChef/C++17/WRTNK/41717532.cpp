#include <bits/stdc++.h>

using namespace std;
#define int long long
const int nax = 1e5 + 66;
const int mod = 1e9 + 7;
int fact[nax], fib[nax], ways[nax];

//n-k+1 C n-2k+1
int power(int a, int b) {
  if(b == 0) return 1;
  int res = power(a, b/2);
  res *= res;
  res %= mod;
  if(b % 2) {
    res = (res * a)%mod;
  }
  return res;
}
int ncr(int n, int r) {
  int P = fact[n];
  int Q = (fact[n-r]*fact[r]) % mod;
  Q = power(Q, mod - 2);
  P = (P * Q) % mod;
  return P;
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
    fact[i] = (i*fact[i-1])%mod;
  }
  fib[0] = 1;
  fib[1] = 2;
  for(int i = 2; i < nax; i++) {
    fib[i] = (fib[i-1] + fib[i-2]) % mod;
  }
  //for(int i = 2; i < nax; i++) {
    //fib[i] = (fib[i] + fib[i-1]) % mod;
  //}
  ways[1] = 1;
  for(int i = 2; i < nax; i++) {
    ways[i] = (ways[i-1] + fib[i-2]) % mod;
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    int answer = ways[n];
    //for(int i = 1; i <= n; i++) {
      //if(1) {
        //if(n-2*i+1>=0) {
          //add_self(answer, ncr(n-i+1, n-2*i+1));
        //} else break;
      //}
    //}
    answer = (answer - ncr(n-k+1, k) + mod) % mod;
    cout << answer << '\n';
  }
  return 0;
}
