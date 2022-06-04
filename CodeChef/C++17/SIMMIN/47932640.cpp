#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests;
  cin >> tests;
  while(tests--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
        cin >> a[i][j];
    }
    int xs, ys, xf, yf;
    cin >> xs >> ys >> xf >> yf;
    int val = a[xs][ys];

    const int INF = 2e9 + 7;

    vector<vector<int>> d(n, vector<int> (m, INF));

    d[xs][ys] = 0;

    queue<pair<int, int>> pq;
    pq.push({xs, ys});

    auto allow = [&](int i, int j) {
      return i >= 0 && j >= 0 && i < n && j < m && a[i][j] == val;
    };

    while(!pq.empty()) {
      int x = pq.front().first;
      int y = pq.front().second;
      pq.pop();
      for(auto it : dir) {
        int xn = x + it.first, yn = y + it.second;
        if(allow(xn, yn) && d[xn][yn] >= INF) {
          d[xn][yn] = d[x][y] + 1;
          pq.push({xn, yn});
        }
      }
    }

    cout << (d[xf][yf] >= INF ? -1 : d[xf][yf]) << '\n';

  }
  return 0;
}