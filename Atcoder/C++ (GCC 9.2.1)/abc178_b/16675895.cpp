#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max({a*c, a*d, b*c, b*d}) << '\n';
  return 0;   
}
