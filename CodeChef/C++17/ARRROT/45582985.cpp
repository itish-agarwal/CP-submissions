#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);  
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for(auto& a : A) 
    cin >> a;

  int s = 0;
  for(auto a : A) {
    s = (s + a + mod*mod) % mod;
    // s = ((s % mod) + (a % mod)) % mod;
  }

  int q;
  cin >> q;
  while(q--) {
    int x;
    cin >> x;
    // s = ((s % mod) + (s % mod) + mod) % mod;
    // s = ((s % mod) + mod) % mod;
    s = (s + s + mod*mod) % mod;
    cout << s << '\n';
  }
}