#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int nax = 1e3 + 7;
  vector<vector<int>> col(nax, vector<int> (nax));
  vector<vector<int>> row(nax, vector<int> (nax));
  vector<vector<int>> A(nax, vector<int> (nax));


  int b = 1;
  int e = 1;

  for(int j = 0; j < nax; ++j) {
    col[0][j] = b;
    b += e;
    e++;

    int x = j + 2;
    for(int i = 1; i < nax; ++i) {
        col[i][j] = col[i-1][j] + x;
        x++;
    }
  }

  for(int i = 0; i < nax; ++i) {
    for(int j = 0; j < nax; j++) {
        row[i][j] = col[i][j];
        A[i][j] = row[i][j];
    }
  }

  for(int j = 0; j < nax; j++) {
    for(int i = 1; i < nax; i++) {
        col[i][j] += col[i-1][j];
    }
  }

  for(int i = 0; i < nax; i++) {
    for(int j =1 ;j<nax; j++) {
        row[i][j] += row[i][j-1];
    }
  }

  int tt;
  cin >> tt;
  while(tt--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x1--;   
    y1--;
    x2--;
    y2--;

    int col_sum = col[x2][y1] - (x1>0 ? col[x1-1][y1] : 0);
    int row_sum = row[x2][y2] - (y1>0 ? row[x2][y1-1] : 0);

    cout << col_sum + row_sum - A[x2][y1] << '\n';
  }
}