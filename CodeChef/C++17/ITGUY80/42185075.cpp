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
    vector<vector<int>> ans(n, vector<int> (n, -1));
    int st = 1;
    for(int j = 0; j < n; ++j) {
      for(int i = j; i < n; ++i) {
        ans[i][j] = st;
        st++;
      }
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; j++) {
        if(ans[i][j] == -1) {
          cout << "*\n";
          break;
        } else {
          cout << ans[i][j];
        }
        //if(i==n-1) {
          //cout << "*\n";
        //}
      }
    }
    cout << "*\n";
  }
}
