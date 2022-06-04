#include <bits/stdc++.h>

using namespace std;
char ans[100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int k;
    cin >> k;
    for(int i = 0; i < 8; ++i) {
      for(int j = 0; j < 8; ++j) {
        if(k > 0) {
          ans[i][j] = '.';
          k --;
        } else {
          ans[i][j] = 'X';
        }
      }
    }
    ans[0][0] = 'O';
    for(int i = 0; i < 8; ++i) {
      for(int j = 0; j < 8; ++j) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}
    
    

