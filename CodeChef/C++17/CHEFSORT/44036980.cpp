#include <bits/stdc++.h>

using namespace std;

void test_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mb = 0;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    for(int bit = 30; bit >= 0; --bit) {
      if((a[i]>>bit) & 1) {
        mb = max(mb, bit);
        break;
      }
    }
  }
  int cnt = 0;
  for(int i = 1; i < n; ++i) {
    if(a[i] < a[i-1]) ++cnt;
  }
  if(cnt <= n/2) {
    cout << cnt << '\n';
    for(int i = 1; i < n; ++i) {
      if(a[i] < a[i-1]) {
        int t = 2, p = i + 1, k = a[i-1] - a[i];
        cout << t << " " << p << " " << k << '\n';
      }
    }
    return;
  }
  mb++;
  int x = (1<<mb) - 1;
  for(auto& it : a) it ^= x;
  vector<vector<int>> ans;
  vector<int> v{4, 1, x};
  ans.push_back(v);
  for(int i = 1; i < n; ++i) {
    if(a[i] < a[i-1]) {
      vector<int> v{2, i+1, a[i-1] - a[i]};
      ans.push_back(v);
    }
  }
  cout << (int) ans.size() << '\n';
  for(auto it : ans) {
    cout << it[0] << " " << it[1] << " " << it[2] << '\n';
  }
}  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    test_case();
  }
  return 0;
}
