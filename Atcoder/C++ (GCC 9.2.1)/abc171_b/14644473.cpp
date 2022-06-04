#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  sort(a.begin(), a.end());
  for(int i = 0; i < k; ++i) {
    ans += a[i];
  }
  cout << ans << '\n';
  return 0;
}