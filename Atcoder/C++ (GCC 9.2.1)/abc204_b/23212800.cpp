#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, x=0;
  cin >> n;
  while(n--) {
    cin >> a;
    if(a > 10) {
      x += a - 10;
    }
  }
  cout << x << '\n';
}