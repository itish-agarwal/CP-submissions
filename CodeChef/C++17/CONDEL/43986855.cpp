#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const ll INF = 2e18 + 77;

void test_case() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll answer = INF;
  int pre[n];
  pre[0] = a[0];
  for(int i = 1; i < n; ++i) {
    pre[i] = pre[i-1] + a[i];
  }
  for(int i = 0; i <= n-k; ++i) {
    int ones = pre[i+k-1] - (i>0 ? pre[i-1] : 0);
    ll pos = (ll)ones*((ll)ones + 1); pos /= 2LL;
    pos += (i>0 ? pre[i-1] : 0);
    pos += pre[n-1] - pre[i+k-1];
    answer = min(answer, pos);
  }
  cout << answer << '\n';
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
