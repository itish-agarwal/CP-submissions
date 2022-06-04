#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto& a : A)
      cin >> a;
    vector<int> pref_gcd(N, A[0]), suff_gcd(N, A[N - 1]);
    vector<int> pref(N, A[0]);
    for(int i = 1; i < N; i++) {
      pref_gcd[i] = __gcd(pref_gcd[i - 1], A[i]);
      pref[i] = pref[i - 1] + A[i];
    }
    for(int i = N - 2; i >= 0; i--) {
      suff_gcd[i] = __gcd(suff_gcd[i + 1], A[i]);
    }
    int ans = pref[N - 1] / pref_gcd[N - 1];
    for(int i = 0; i < N; i++) {
      int left_gcd = (i > 0 ? pref_gcd[i - 1] : 0);
      int right_gcd = (i + 1 < N ? suff_gcd[i + 1] : 0);
      int g = __gcd(left_gcd, right_gcd);
      int sum = pref[N - 1] - A[i];
      if(sum > 0) {
        ans = min(ans, sum / g + 1);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}