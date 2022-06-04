#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long 

int power(int a, int b) {
  int ans = 1;
  while(b--) {
    ans *= a;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s = to_string(n);
  if((int)s.size() <= 3) {
    cout << "0\n";
    return 0;
  }
  int ans = 0;
  for(int l = 1; l < (int) s.size(); ++l) {
    ans += 9*power(10, l-1)*((l-1)/3);
  }
  string mx = "";
  for(int i = 1; i < (int) s.size(); ++i) {
    mx += '9';
  }
  int k = stoll(mx);
  int left = n - k;
  //cout << left << '\n';
  ans += left*(((int)s.size()-1)/3);
  cout << ans << '\n';
}
