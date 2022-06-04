#include <bits/stdc++.h>

using namespace std;
// #define int long long 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int ans = 0;

  for(int i = 0; i < n; i++) {
    ans = max(ans, a[i] * (n - i));
  }

  cout << ans << '\n';
}