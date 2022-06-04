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
    int a[n][n];
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> a[i][j];
        if(i == j || i + j == n - 1) {
          ans += a[i][j];
        }
      }
    }
    cout << ans << '\n';
  }
}