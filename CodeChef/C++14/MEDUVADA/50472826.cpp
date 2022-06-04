#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }

template <class T, class V> void pr(const pair<T, V> &x);
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
template <class T> void pr(const set<T>& pq);

template <class T, class V> void pr(const pair<T, V>& x) {
  cout << "{"; pr(x.first); cout << ", "; pr(x.second); cout << "}";
}
template <class T, class V> void pr(const map<T, V>& mp) {
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it); auto copy = it;
    if(++copy != mp.end()) 
      cout << " ";
  }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values;
  for(auto& value : pq) 
    values.push_back(value);

  pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) {
    pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : "");
  }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values;
  for(auto value : pq)
    values.push_back(value);

  pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins

vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void test_case() {
  int N, M;
  cin >> N >> M;

  vector<string> grid(N);
  for (auto &row : grid)
    cin >> row;

  pair<int, int> mouse, dosa;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if(grid[i][j] == 'M') {
        mouse = {i, j};
      }
      if(grid[i][j] == 'D') {
        dosa = {i, j};
      }
    }
  }

  auto allow = [&](int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
  };

  vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>> (M, {-1, -1}));
  vector<vector<int>> d(N, vector<int> (M, -1));

  d[mouse.first][mouse.second] = 0;
  queue<pair<int, int>> q;

  q.push({mouse.first, mouse.second});

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(auto it : dir) {
      int xn = x + it.first;
      int yn = y + it.second;
      if(allow(xn, yn) && grid[xn][yn] != '#' && d[xn][yn] == -1) {
        d[xn][yn] = d[x][y] + 1;
        parent[xn][yn] = {x, y};
        q.push({xn, yn});
      }
    }

    if(x == 0 || x == N - 1) {
      int xn = N - 1 - x;
      int yn = y;
      if(allow(xn, yn) && grid[xn][yn] != '#' && d[xn][yn] == -1) {
        d[xn][yn] = d[x][y] + 1;
        parent[xn][yn] = {x, y};
        q.push({xn, yn});
      }
    }

    if(y == 0 || y == M - 1) {
      int xn = x;
      int yn = M - 1 - y;
      if(allow(xn, yn) && grid[xn][yn] != '#' && d[xn][yn] == -1) {
        d[xn][yn] = d[x][y] + 1;
        parent[xn][yn] = {x, y};
        q.push({xn, yn});
      }
    }
  }

  if(d[dosa.first][dosa.second] == -1) {
    cout << "NO" << '\n';
    return;
  }

  int x = dosa.first, y = dosa.second;
  // debug(parent[dosa.first][dosa.second]);

  while(x != mouse.first || y != mouse.second) {
    if(grid[x][y] == '.')
      grid[x][y] = 'x';

    auto p = parent[x][y];
    x = p.first;
    y = p.second;
  }

  cout << "YES" << '\n';

  for (auto& row : grid)
    cout << row << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();

}