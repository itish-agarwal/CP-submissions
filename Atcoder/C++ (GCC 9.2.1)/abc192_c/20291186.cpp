#include <bits/stdc++.h>

using namespace std;
#define int long long

int f(int n) {
  string s = to_string(n);
  string t = s;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  int g1 = stoi(t);
  int g2 = stoi(s);
  return g1 - g2;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int a = n;
  for(int i = 0; i < k; ++i) {
    a = f(a);
  }
  cout << a << '\n';
}
