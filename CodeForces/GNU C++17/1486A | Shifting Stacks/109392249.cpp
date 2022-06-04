#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
void test_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto&it : a) cin >> it;
  for(int i = 0; i < n; ++i) {
    if(a[i] < i) {
      puts("NO");
      return;
    }
    if(i+1 < n) {
      a[i+1] += a[i] - i;
    }
  }
  puts("YES");
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