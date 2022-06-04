#include <bits/stdc++.h>

using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x;
  cin >> x;
  long long ans = (x/500)*1000;
  x %= 500;
  ans += (x/5)*5;
  cout<<ans<<'\n';
  return 0;
}
