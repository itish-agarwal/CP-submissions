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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }  
    vector<int> cnt(31);
    for (int i = 0; i < n; ++i) {
      for (int b = 0; b < 31; ++b) {
        if (a[i] >> b & 1) {
          cnt[b]++;
        }
      }
    }
    int ans = 0;
    for (int b = 0; b < 31; ++b) {
      if (cnt[b] > 1) {
        ans ^= 1 << b;
      }
    }
    cout << ans << '\n';
  }
}