#include <bits/stdc++.h>

using namespace std;

int longest(vector<int> a) {
  std::vector<int> in;
  int n = a.size();
  in.push_back(-1);
  for(int i = 0; i < n; ++i) {
    if(!a[i]) {
      in.push_back(i);
    }
  }
  in.push_back(n);
  int res = 0;
  for(int i = 1; i < (int)in.size(); ++i) {
    res = max(res, in[i] - in[i-1] - 1);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for(int i = 0; i < n; ++i) a[i] = s[i] - '0';
    int ans = longest(a);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i != j) {
          swap(a[i], a[j]);
          ans = max(ans, longest(a));
          swap(a[i], a[j]);
        }
      }
    }
    cout << ans << '\n';
  }
}