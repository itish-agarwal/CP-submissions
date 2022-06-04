#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> line;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      line.insert(a[i]);
    }
    int q;
    cin >> q;
    while(q--) {
      int x, y;
      cin >> x >> y;
      if(line.find(x + y) == line.end()) {
        int ans = 0;
        if(x + y > a[n - 1]) {
          ans = n;
        } else {
          int L = 0;
          int R = n - 1;
          while(L <= R) {
            int mid = (L + R) / 2;
            if(x + y < a[mid]) {
              if(mid > 0 && x + y > a[mid - 1]) {
                ans = mid;
              }
              R = mid - 1;
            } else {
              if(mid < (n - 1) && x + y < a[mid + 1]) {
                ans = mid + 1;
              }
              L = mid + 1;
            }
          }
        }        
        cout << ans << '\n';        
      } else {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}
