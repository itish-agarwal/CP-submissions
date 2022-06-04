#include <bits/stdc++.h>

using namespace std;
#define int long long 
int w, h, a, b, m, c;

int ceil(int x, int y) {
  return (x + y - 1)/y;
}
int solve() {
  //w -> a
  //h -> b
  int ans = 0;
  if(w%a && h%b) {
    int x = ceil(w, a), y = ceil(h, b);
    ans += ceil(x*y, 10)*m;
    ans += (h + w) * c;
    return ans;
  }
  if(!w%a && h%b) {
    int x = w/a, y = ceil(h, b);
    ans += ceil(x*y, 10)*m;
    ans += h * c;
    return ans;
  } 
  if(w%a && !h%b) {
    int x = ceil(w, a), y = h/b;
    ans += ceil(x*y, 10)*m;
    ans += w * c;
    return ans;
  }
  int x = w/a, y = h/b;
  return ceil(x*y, 10)*m;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  cin >> w >> h >> a >> b >> m >> c;
  int ans = solve();
  cout << ans << endl;
}

