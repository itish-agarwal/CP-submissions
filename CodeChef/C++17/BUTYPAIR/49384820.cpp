#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n, a;
    cin >> n;
    int ans = n * (n - 1);
    map<int, int> freq;
    while(n--) {
      cin >> a;
      freq[a]++;
    }
    for(auto it : freq) {
      int f = it.second;
      ans -= f * (f - 1);
    }
    cout << ans << '\n';
  }
}