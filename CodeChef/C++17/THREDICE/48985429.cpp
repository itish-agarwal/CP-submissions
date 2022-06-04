#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while(T--) {
    int X, Y;
    cin >> X >> Y;

    int fav = max(0, 6 - X - Y);

    cout << double(fav) / 6 << '\n';
  }
}
