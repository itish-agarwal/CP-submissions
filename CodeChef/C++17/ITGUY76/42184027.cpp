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
    vector<vector<char>> ans(x, vector<char> (n, '0'));
    for(int i = 0; i < x; ++i) {
      for(int j = 0; j < n; ++j) {
        if(j==n/2) {
          ans[i][j] = '*';
        }
      }
    }
    for(int i = 0; i < x; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i==j) {
          ans[i][j] = '*';
        }
      }
    }
     for(int i = 0; i < x; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i+j==n-1) {
          ans[i][j] = '*';
        }
      }
    }
    for(int i = 0; i < x; ++i) {
      for(int j = 0; j < n; ++j) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}
    
