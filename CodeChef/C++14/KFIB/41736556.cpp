#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
void sub_self(int& a, int b) {
  a -= b;
  if(a < 0) {
    a += mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int s = 0;
  vector<int> f(n+1);
  for(int i = 1; i <= n; i++) {
    if(i <= k) {
      f[i] = 1;
      s++;
    } else {
      f[i] = s;
      add_self(s, f[i]);
      sub_self(s, f[i-k]);
    }
  }
  cout << f[n] << '\n';
  return 0;
}
