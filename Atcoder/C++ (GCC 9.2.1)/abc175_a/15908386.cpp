#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& x : a) cin >> x;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        if(a[i]!=a[j] && a[j]!=a[k] && a[k]!=a[i]) {
          if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i]) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
