#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
void test_case() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  if(n & 1) {
    cout << "1\n";
    return;
  }
  int X = x[n/2] - x[n/2-1] + 1;
  int Y = y[n/2] - y[n/2-1] + 1;
  cout << X*Y << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
}