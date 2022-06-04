#include <bits/stdc++.h>

using namespace std;

vector<int> compare(const vector<int>& a, const vector<int>& b) {
  int n = a.size();
  for(int i = 0; i < n; ++i) {
    if(a[i] < b[i]) 
      return a;
    if(b[i] < a[i]) 
      return b;
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(n);
    for(int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    vector<vector<int>> rem(n);
    int mn = n;
    for(int i = 0; i < n; ++i) {
      rem[(a[0] + b[i]) % n].push_back(i);
      mn = min(mn, (a[0] + b[i]) % n);
    }
    vector<int> ans(n, n);
    for(int in : rem[mn]) {
      vector<int> c(n);
      for(int i = 0; i < n; ++i) {
        c[i] = (a[i] + b[(i + in) % n]) % n;
      }
      ans = compare(ans, c);
    }
    for(int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
}