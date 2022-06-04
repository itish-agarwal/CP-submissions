#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cpp_int n;
    cin >> n;
    cpp_int ans = 1;
    for(int i = 1; i <= n; ++i) {
      ans *= i;
    }
    cout << ans << '\n';
  }
}
