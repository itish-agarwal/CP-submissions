#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests;
  cin >> tests;
  while(tests--) {
    int N, K;
    string S;
    cin >> N >> K >> S;

    vector<int> d;
    for(int i = 1; i < N; i++)
      d.emplace_back((S[i] == S[i - 1] ? 0 : 1));

    long long ans = 0;
    if(K < N) {
      long long s = 0;
      for(int i = 0; i < K; i++)
        s += d[i];

      ans = s;
      for(int i = K; i < N - 1; i++) {
        s -= d[i - K];
        s += d[i];
        ans += s;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}