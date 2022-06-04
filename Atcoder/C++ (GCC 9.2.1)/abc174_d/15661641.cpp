#include <bits/stdc++.h>

using namespace std;
const int nax = 2e5 + 5;
int a[nax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int L = 0, R = 1e9 + 1, ans = a[n - 1];
  while(R - L > 1) {
    int mid = L + (R - L)/2;
    long long reqd = 0;
    for(int i = 0; i < n; i++) {
      if(reqd > k) break;
      reqd += ((a[i] + mid - 1)/mid) - 1;
    }
    if(reqd <= k) {
      ans = mid;
      R = mid;
    } else {
      L = mid;
    }
  }
  cout << ans << '\n';
  return 0;
}
