#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 2e18 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dist(n, vector<int> (n, INF));
  for(int i = 0; i < n; i++)
    dist[i][i] = 0;

  for(int i = 0 ; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    dist[a][b] = min(dist[a][b], w);
  }

  int ans = 0;  

  vector<vector<int>> d(n, vector<int> (n, INF));

  for(int i = 0; i < n; i++)
    d[i][i] = 0;

  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(d[i][j] < INF)
          ans += min(d[i][j], dist[i][j]);
        else if(dist[i][j] < INF)
          ans += min(d[i][j], dist[i][j]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}