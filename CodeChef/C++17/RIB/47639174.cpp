#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> a;
  for(int i = 0; i < N; i++) {
    int u, v;
    char ch;
    cin >> u >> v >> ch;
    a.emplace_back((x-u)*(x-u) + (y-v)*(y-v), ch == 'S');
  }
  sort(a.begin(), a.end());
  int sulphuric = 0;
  for(int i = 0; i < K; i++) {
    sulphuric += a[i].second;
  }
  if(sulphuric > K - sulphuric) {
    cout << "IT IS EXHILARATING\n";
  } else {
    cout << "EASY AS CAKE\n";
  } 
}