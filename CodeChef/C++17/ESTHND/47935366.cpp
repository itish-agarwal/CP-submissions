#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int INF = 2e16 + 7;

int N, K, curr[2001], pred[2001], vis[2001];
vector<vector<int>> edges;

int dp[2005][2005], visited[2005][2005];

int rec(int i, vector<pair<int, int>>& x, int sum_so_far) {
  if(sum_so_far > K)
    return -INF;
  if(i == (int)x.size())
    return 0;
  if(visited[i][sum_so_far])
    return dp[i][sum_so_far];
  int ans = rec(i + 1, x, sum_so_far);
  ans = max(ans, rec(i + 1, x, sum_so_far + x[i].first) + x[i].second - x[i].first);
  visited[i][sum_so_far] = 1;
  return dp[i][sum_so_far] = ans;
}

int profit(vector<pair<int, int>> x) {
  // memset(visited, 0, sizeof(visited));
  for(int i = 0; i <= (int)x.size(); i++) {
    for(int j = 0; j <= K; j++)
      visited[i][j] = 0;
  }
  return rec(0, x, 0);
}

void Dfs(int u, vector<pair<int, int>>& x) {
  if(vis[u])
    return;
  vis[u] = 1;
  x.emplace_back(curr[u], pred[u]);
  for(int v : edges[u]) 
    Dfs(v, x);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;
  edges.resize(N);

  int m;
  cin >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for(int i = 0; i < N; i++)
    cin >> curr[i];

  for(int i = 0; i < N; i++)
    cin >> pred[i];

  int ans = 0;

  for(int i = 0; i < N; i++) {
    if(!vis[i]) {
      vector<pair<int, int>> x;
      Dfs(i, x);
      ans += profit(x);
    }
  }

  cout << ans << '\n';
  return 0;

}
