#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector<int> A(N);

    for(auto& a : A)
      cin >> a;

    sort(A.begin(), A.end());
    int ans = 0;

    for(int i = 0; i < N/2; ++i) {
      ans += A[N-i-1] - A[i];
    }

    cout << ans << '\n';
  }
}