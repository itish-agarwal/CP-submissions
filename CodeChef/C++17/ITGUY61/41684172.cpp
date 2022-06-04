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
    n = 2*n - 1;
    vector<vector<int>> g(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i==j || i+j==n-1) {
          g[i][j] = 1;
        }
      }
    }
    for(int i = 0; i < n; i++) {
      int c = 0;
      for(int j = 0; j < n; j++) {
        if(g[i][j]) {
          c++;
        }
      }
      if(c == 1) {
        for(int j = 0; j < n; j++) {
          if(g[i][j]) {
            cout << 1;
          } else {
            cout << " ";
          }
        }
      } else {
        c = 0;
        for(int j = 0; j < n; j++) {
          if(g[i][j]) c++;
          if(g[i][j]) {
            cout << 1;
          } else {
            if(c == 1) {
              cout << 1;
            } else {
              cout << " ";
            }
          }
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
