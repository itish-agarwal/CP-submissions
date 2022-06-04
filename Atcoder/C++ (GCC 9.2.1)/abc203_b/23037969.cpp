#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ans=0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= k; j++) {
      int x = 100*i + j;
      ans += x;
    }
  }
  cout << ans << '\n';
}