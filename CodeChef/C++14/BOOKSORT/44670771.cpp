#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), ans;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(auto it : a) {
    if(ans.empty() || it > ans.back()) {
      ans.push_back(it);
      continue;
    }
    int in = upper_bound(ans.begin(), ans.end(), it) - ans.begin();
    if(it < ans[in]) {
      ans[in] = it;
    }
  }
  cout << n - (int)ans.size() << endl;
}