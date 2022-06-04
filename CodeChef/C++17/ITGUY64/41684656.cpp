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
        if(i==0 || i==n-1 || i==j || i+j==n-1) {
          g[i][j] = j + 1;
        }
        if(g[i][j]) {
          cout << g[i][j];
        } else {
          cout << " " ;
        }
      }
      cout << '\n';
    }
  }    
  return 0;
}
