#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 1e9 + 7;

int power(int a, int b) {
  if(b == 0) return 1;
  int res = power(a, b/2);
  res = (res * res) % mod;
  if(b % 2) {
    res = (res * a) % mod;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N, M;
    cin >> N >> M;
    int x = (power(2, N) - 1 + mod) % mod;
    cout << power(x, M) << '\n';
  }
}