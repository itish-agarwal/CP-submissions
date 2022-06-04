#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int dist = abs(c - a) + abs(b - d);
    if(dist%2 == k%2 && dist <= k) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}