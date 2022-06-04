#include <bits/stdc++.h>

using namespace std;
#define int long long 

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lcm = a[0];
    for(int i = 1; i < n; i++) {
        lcm = (a[i] * lcm) / __gcd(a[i], lcm);
        if(lcm > k) {
            cout << 0 << '\n';
            return;
        }
    }
    cout << k / lcm << '\n';
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