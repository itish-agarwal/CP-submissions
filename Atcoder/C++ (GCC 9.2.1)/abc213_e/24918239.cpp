#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9 + 7;

const vector<pair<int, int>> dir{{2, -1}, {2, 0}, {2, 1}, 
{1, -2}, {1, -1}, {1, 0}, {1, 1}, {1, 2},
{0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2},
{-1, -2}, {-1, -1}, {-1, 0}, {-1, 1}, {-1, 2},
{-2, -1}, {-2, 0}, {-2, 1}};

const vector<pair<int, int>> normal{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char> (m));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  
  auto in_bounds = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };

  vector<vector<int>> d(n, vector<int> (m, INF));
  d[0][0] = 0;

  set<tuple<int, int, int>> pq;
  pq.insert(make_tuple(0, 0, 0));

  while(!pq.empty()) {
    int x = get<1>(*pq.begin());
    int y = get<2>(*pq.begin());
    pq.erase(pq.begin());
    for(auto it : normal) {
      int xn = x + it.first;
      int yn = y + it.second;
      if(in_bounds(xn, yn) && g[xn][yn] == '.') {
        if(d[x][y] < d[xn][yn]) {
          pq.erase(make_tuple(d[xn][yn], xn, yn));
          d[xn][yn] = d[x][y];
          pq.insert(make_tuple(d[xn][yn], xn, yn));
        }
      }
    }
    for(auto it : dir) {
      int xn = x + it.first;
      int yn = y + it.second;
      if(in_bounds(xn, yn) && d[x][y] + 1 < d[xn][yn]) {
        pq.erase(make_tuple(d[xn][yn], xn, yn));
        d[xn][yn] = d[x][y] + 1;
        pq.insert(make_tuple(d[xn][yn], xn, yn));
      }
    }
  }

  cout << d[n-1][m-1] << '\n';
}