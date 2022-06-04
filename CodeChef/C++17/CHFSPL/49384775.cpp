#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int A, B, C;
    cin >> A >> B >> C;
    cout << A + B + C - min({A, B, C}) << '\n';
  }
}