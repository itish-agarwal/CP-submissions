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
    int ans[n][n];
    int st = n;
    bool rr = 1;
    int x = 0, y = 0;
    int l = 0, r = n;
    for(int i = 0; i < n; i++) {
      for(int j = st*st; j > (st-1)*(st-1); j--) {
        ans[x][y] = j;
        if(rr) {
          y++;
          if(y>=r) {
            y--;
            x++;
          }
        } else {
          y--;
          if(y<l) {
            y++;
            x--;
          }
        }
      }
      st--;
      if(rr) {
        x--;
        y--;
        r--;
      } else {
        y++;
        x++;
        l++;
      }
      rr = !rr;
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << ans[i][j] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
      
    

