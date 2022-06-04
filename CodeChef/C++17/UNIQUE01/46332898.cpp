#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;
  while(tt--) {
    int n, a;
    cin >> n;
    int x = 0;
    while(n--) {
      cin >> a;
      x ^= a;
    }
    cout << x << '\n';
  }
}