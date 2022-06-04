#include <bits/stdc++.h>

using namespace std;
#define int long long

const int INF = 2e18 + 7;
const int nax = 240;
int dist[nax][nax];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i!=j) {
        dist[i][j] = INF;
      }
    }
  }
  while(m--) {
    int a, b, w;
    cin >> a >> b >> w;
    --a;
    --b;
    dist[a][b] = dist[b][a] = w;
  }
  //Run the flyod warshall loops
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  int answer = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      answer = max(answer, dist[i][j]);
    }
  }
  // cout << dist[0][3] << endl;
  cout << answer << '\n';
  return 0;
}
