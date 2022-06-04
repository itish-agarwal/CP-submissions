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
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i==0 || j==0 || i==n-1 || j==n-1 || i==j || i+j==n-1) {
          cout << 1;
        } else {
          cout << " ";
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
