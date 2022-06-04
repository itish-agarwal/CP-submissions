#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while(tests--) {
    long long A, B;
    cin >> A >> B;

    cout << __gcd(A, B) << " " << A / __gcd(A, B) * B << '\n';

  }
  return 0;
}