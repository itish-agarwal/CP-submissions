#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int answer = 1e6 + 1;
    while(n--) {
      int x;
      cin >> x;
      answer = min(answer, x);
    }
    cout << answer << '\n';
  }
  return 0;
}
