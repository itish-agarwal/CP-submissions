#include <bits/stdc++.h>

using namespace std;
const int inf = 2e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W, N;
  cin >> H >> W >> N;
  int min_x = inf, min_y = inf;
  vector<tuple<int, int, int>> pts;
  for(int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    pts.push_back({y, x, i});
  }
  sort(pts.begin(), pts.end());
  // for(auto it : pts) {
  //   cout << get<0>(it) << " " << get<1>(it) << endl;
  // }
  // cout<<endl;
  vector<int> yy(N, 1);
  for(int i = 1; i < N; ++i) {
    yy[i] = yy[i-1];
    if(get<0>(pts[i]) != get<0>(pts[i-1])) {
      yy[i]++;
    }
  }
  for(int i = 0; i < N; ++i) {
    get<0>(pts[i]) = yy[i];
  }
  // for(auto it : pts) {
  //   cout << get<0>(it) << " " << get<1>(it) << endl;
  // }
  // cout<<endl;
  for(auto& it : pts) {
    swap(get<0>(it), get<1>(it));
  }
  sort(pts.begin(), pts.end());
  vector<int> xx(N, 1);
  for(int i = 1; i < N; ++i) {
    xx[i] = xx[i-1];
    if(get<0>(pts[i]) != get<0>(pts[i-1])) {
      xx[i]++;
    }
  }
  for(int i = 0; i < N; ++i) {
    get<0>(pts[i]) = xx[i];
  }
  vector<int> X(N), Y(N);
  for(auto it : pts) {
    int in = get<2>(it);
    X[in] = get<0>(it);
    Y[in] = get<1>(it);
  }
  for(int i = 0; i < N; ++i) 
    cout << X[i] << " " << Y[i] << '\n';

  return 0;
}