#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;

  while(T--) {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);

    for(auto& a : A) {
      cin >> a;
      a %= 2;
    }

    for(int i = 1; i < N; ++i) {
      A[i] += A[i-1];
    }

    for(int q = 0; q < Q; ++q) {
      int L, R;
      cin >> L >> R;
      --L;
      --R;
      int total = R - L + 1, odd = A[R] - (L > 0 ? A[L-1] : 0), even = total - odd;
      long long ans = ((long long)total * (total - 1) * (total - 2)) / 6;
      ans -= (long long) odd * (even * (even - 1) / 2);
      ans -= ((long long)odd * (odd - 1) * (odd - 2)) / 6;

      cout << ans << '\n';
    } 
  }

  return 0;
}