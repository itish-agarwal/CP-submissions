#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, int> mp;
  // mp[0] = 1;

  long long ans = 0;
  for(int x : a) {
    ans += mp[x % 200];
    mp[x % 200] += 1;
  }

  cout << ans << '\n';
}