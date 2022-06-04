#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    char g[n][m];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> g[i][j];
      }
    }
    int ans = 2e8 + 777;
    char g0[n][m], g1[n][m];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(i % 2) {
          if(j % 2) {
            g0[i][j] = '.';
            g1[i][j] = '*';
          } else {
            g0[i][j] = '*';
            g1[i][j] = '.';
          }
        } else {
          if(j % 2) {
            g0[i][j] = '*';
            g1[i][j] = '.';
          } else {
            g0[i][j] = '.';
            g1[i][j] = '*';
          }
        }
      }
    }
    int m0 = 0, m1 = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        m0 += (g[i][j]!=g0[i][j]);
        m1 += (g[i][j]!=g1[i][j]);
      }
    }
    if((n*m) % 2) {
      cout << m1 << '\n';
    } else {
      cout << min(m0, m1) << '\n';
    }
  }
  return 0;
}
