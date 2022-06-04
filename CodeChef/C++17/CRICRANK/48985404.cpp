#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while(T--) {
    int R1, W1, C1, R2, W2, C2;
    cin >> R1 >> W1 >> C1 >> R2 >> W2 >> C2;

    int A = (R1 > R2) + (W1 > W2) + (C1 > C2);

    cout << (A > 3 - A ? "A" : "B") << '\n';
  }
}