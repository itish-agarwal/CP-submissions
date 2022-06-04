#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> row, col;
    row.push_back(-1);
    col.push_back(-1);
    while(n--) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      row.push_back(x);
      col.push_back(y);
    }
    row.push_back(h);
    col.push_back(w);
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    int a = -1, b = -1;
    for(int i = 1; i < (int)row.size(); ++i) {
      a = max(a, row[i] - row[i-1] - 1);
    }
    for(int i = 1; i < (int)col.size(); ++i) {
      b = max(b, col[i] - col[i-1] - 1);
    }
    //cout << a << " " << b << '\n';
    cout << a * b << '\n';
  }
}
