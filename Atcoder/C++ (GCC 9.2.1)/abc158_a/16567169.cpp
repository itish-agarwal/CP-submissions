#include <bits/stdc++.h>

using namespace std;
#define int long long
int x, y, a, b, c, p[100001], q[100001], r[100001];
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> x >> y >> a >> b >> c;
  //we have to eat x red and y green;
  for(int i = 0; i < a; i++) {
    cin >> p[i];
  }
  for(int i = 0; i < b; i++) {
    cin >> q[i];
  }
  for(int i = 0; i < c; i++) {
    cin >> r[i];
  }
  int ans = 0;
  sort(p, p + a, greater<int>());
  sort(q, q + b, greater<int>());
  sort(r, r + c);
  vector<int> f;
  for(int i = 0; i < x; i++) {
    f.push_back(p[i]);
  }
  for(int i = 0; i < y; i++) {
    f.push_back(q[i]);
  }
  sort(f.rbegin(), f.rend());
  int i = c-1, j = x+y-1;
  while(i>=0 && j>=0 && r[i] > f[j]) {
    f[j] = r[i];
    i--;
    j--;
  } 
  for(int x : f) ans += x;
  cout << ans << '\n';
  return 0;
}
