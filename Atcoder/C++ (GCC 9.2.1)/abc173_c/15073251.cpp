#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int row, col, k;
  char grid[10][10];
  cin >> row >> col >> k;
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < col; ++j) {
      cin >> grid[i][j];
    }
  }  
  int ans = 0;
  for(int maskr = 0; maskr < (1 << row); maskr++) {
    for(int maskc = 0; maskc < (1 << col); maskc++) {
      set<int> ret, cet;
      for(int bit = 0; bit < row; ++bit) {
        if(maskr & (1 << bit)) {
          ret.insert(bit);
        }
      }
      for(int bit = 0; bit < col; ++bit) {
        if(maskc & (1 << bit)) {
          cet.insert(bit);
        }
      }
      int foo = 0;
      for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
          if(ret.find(i)==ret.end() && cet.find(j)==cet.end() && grid[i][j]=='#') {
            ++foo;
          }
        }
      }
      if(foo == k) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
