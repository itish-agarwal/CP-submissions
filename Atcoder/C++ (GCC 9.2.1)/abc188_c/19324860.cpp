#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(1<<n), b(1<<n);
  for(auto& x : a) cin >> x;
  iota(b.begin(), b.end(), 0);
  while(1) {
    if((int)b.size() == 2) {
      if(a[b[0]] > a[b[1]]) {
        cout << b[1] + 1 << '\n';
      } else cout << b[0] + 1 << '\n';
      return 0;
    }
    vector<int> c;
    for(int i = 1; i < (int)b.size(); i += 2) {
      if(a[b[i]] > a[b[i-1]]) {
        c.push_back(b[i]);
      } else c.push_back(b[i-1]);
    }
    b = c;
  }
  return 0;
}
