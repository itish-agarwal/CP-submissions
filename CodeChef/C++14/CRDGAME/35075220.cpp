#include <bits/stdc++.h>

using namespace std;

int f(int n) {
  int ans = 0;
  while(n > 0) {
    ans += n%10;
    n/=10;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    int aa = 0, bb = 0;
    for(int i = 0; i < n; ++i) {
      if(f(a[i]) > f(b[i])) {
        aa++;
      } else if(f(b[i]) > f(a[i])) {
        bb++;
      } else {
        aa++; bb++;
      }
    }
    if(aa > bb) {
      cout << 0 << " " << aa << '\n';
    } else if(bb > aa) {
      cout << 1 << " " << bb << '\n';
    } else {
      cout << 2 << " " << aa << '\n';
    }
  }
  return 0;
}
