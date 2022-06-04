#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int gcd = 0;
  while(n--) {
    int x;
    cin >> x;
    gcd = __gcd(gcd, x);
  }
  cout<<gcd<<'\n';
  return 0;
}
