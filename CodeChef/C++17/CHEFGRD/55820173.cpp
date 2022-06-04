#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    int xf = (n + 1) / 2, yf = (n + 1) / 2;
    int a = x + y, b = xf + yf;
    cout << (a % 2 == b % 2 ? 0 : 1) << '\n';   
  }
}