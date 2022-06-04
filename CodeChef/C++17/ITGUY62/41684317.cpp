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
    int N = n;
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
      int c = 0, st = i + 1;
      if(i >= N) st = n - i;
      for(int j = 0; j < n; j++) {
        if(g[i][j]) {
          c++;
        }
      }
      if(c == 1) {
        for(int j = 0; j < n; j++) {
          if(g[i][j]) {
            cout << st;
          } else {
            cout << " ";
          }
        }
      } else {
        c = 0;
        for(int j = 0; j < n; j++) {
          if(g[i][j]) c++;
          if(g[i][j]) {
            cout << st;
            st++;
          } else {
            if(c == 1) {
              cout << st;
              st++;
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
