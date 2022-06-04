#include <bits/stdc++.h>

using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, a, b, tt, ans;
  cin >> n >> a >> b;
  tt = n/(a+b);
  ans = tt*a;
  n %= (a + b);
  if(n < a) {
    ans += n;
  } else {
    ans += a;
  }
  cout<<ans<<'\n';
  return 0;
}
