#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if((i&1) && (a&1)) ans++;
  }
  cout << ans << '\n';
  return 0;
}
