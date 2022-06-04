#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests;
  cin >> tests;
  while(tests--) {
    int N;
    string S;
    cin >> N >> S;

    int ans = N;

    for(char ch = 'a'; ch <= 'z'; ch++) {
      int g = 0, x = 0;
      for(int i = 0; i < N; i++) {
        if(S[i] == ch) {
          g = __gcd(g, i);
          x += 1;
        }
      }
      if(g > 1)
        ans = min(ans, N - x + 1);
    }

    cout << ans << '\n';

  }
  return 0;
}