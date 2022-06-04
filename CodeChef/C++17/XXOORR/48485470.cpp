#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(31);
    for(int i = 0; i < n; i++) {
      int a;
      cin >> a;
      for(int b = 0; b <= 30; b++) {
        cnt[b] += (a & (1 << b)) ? 1 : 0;
      }
    }
    int ans = 0;
    for(int i = 0; i <= 30; i++) {
      ans += (cnt[i] + k - 1) / k;
    }
    cout << ans << '\n';
  }
  return 0;
}