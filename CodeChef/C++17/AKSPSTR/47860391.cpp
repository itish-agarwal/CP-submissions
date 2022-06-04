#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while(tests--) {
    int N, ok = 1;
    string S, T;
    cin >> N >> S >> T;
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    for(int i = 1; i < N; i++) {
      if(T[i] - S[i] != T[i - 1] - S[i - 1]) {
        ok = 0;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}