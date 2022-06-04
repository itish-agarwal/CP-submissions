#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  if(s.back() == 's') s += "es";
  else s += "s";
  cout << s << '\n';
}
