#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> S(n);
  for(int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  vector<int> T(n);
  for(int i = 0; i < n; ++i) {
    cin >> T[i];
  }
  const int INF = 2e9 + 7;
  vector<int> ans = T;
  for(int i = 0; i < n; ++i) {
    ans[i] = min(ans[i], T[i]);
    ans[(i+1)%n] = min(ans[(i+1)%n], ans[i] + S[i]);
  }
  for(int i = 0; i < n; ++i) {
    ans[i] = min(ans[i], T[i]);
    ans[(i+1)%n] = min(ans[(i+1)%n], ans[i] + S[i]);
  }
  for(int x : ans) {
    cout << x << '\n';
  }
  cout << '\n';
}