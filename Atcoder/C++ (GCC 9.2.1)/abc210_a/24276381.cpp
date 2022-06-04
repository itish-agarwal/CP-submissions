#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, A, X, Y;
  cin >> N >> A >> X >> Y;

  int ans = min(N, A) * X;

  ans += max(0, N - A) * Y;
  cout << ans << '\n';
}