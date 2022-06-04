#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long N;
  cin >> N;

  long long val = 1, p = 0;

  while(2 * val <= N) {
    val *= 2;
    p += 1;
  }

  cout << p << '\n';
}