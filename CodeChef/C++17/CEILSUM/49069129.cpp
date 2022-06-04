#include <bits/stdc++.h>

using namespace std;

int ceil(int a) {
  if(a >= 0) {
    return (a + 1) / 2;
  }
  a = -a;
  return -1 * (a / 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int A, B;
    cin >> A >> B;
    int ans = -2e9-7;
    int mid = (A + B) / 2;
    for(int X = max(min(A, B), mid - 100); X <= min(max(A, B), mid + 100); ++X) {
      ans = max(ans, ceil(B-X) + ceil(X-A));
    }
    cout << ans << '\n';
  }
}