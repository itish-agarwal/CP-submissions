#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x;
    cin >> x;
    int n = x + x - 1;
    vector<vector<char>> ans(x, vector<char> (n, ' '));
    ans[0][n/2] = (x % 2 ? '*' : 'A');
    int l = n/2 - 1, r = n/2 + 1;
    bool star = (x % 2 ? 0 : 1);
    int st = 1;
    while(l >= 0) {
      for(int i = st; i < x; ++i) {
        ans[i][l] = ans[i][r] = (star ? '*' : 'A');
      }
      st++;
      star = !star;
      l--;
      r++;
    }
    for(int i = 0; i < x; ++i) {
      for(int j = 0; j < n; ++j) {
        if(j==n/2) {
          if(x%2) {
            cout << '*';
          } else {
            cout << 'A';
          }
        }
        else cout << ans[i][j];
      }cout<<'\n';
    }
  }
}
