#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int INF = 2e18 + 7;

void test_case() {
  int N, M, K;
  string S;
  cin >> N >> M >> K >> S;

  vector<vector<int>> d(10, vector<int> (10, INF));
  for(int r = 0; r < 10; ++r) 
    d[r][r] = 0;

  for(int e = 0; e < M; ++e) {
    int x, y, w;
    cin >> x >> y >> w;
    d[x][y] = min(d[x][y], w);
  }

  for(int k = 0; k < 10; ++k) 
    for(int i = 0; i < 10; ++i) 
      for(int j = 0; j < 10; ++j) 
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  vector<int> suffix_sum(N/2 + 1);

  for(int i = 0; i < N/2; ++i) {
    int need = INF;

    for(int dg = 0; dg < 10; ++dg) 
      need = min(need, d[S[i]-'0'][dg] + d[S[N-i-1]-'0'][dg]);

    suffix_sum[i] = need;
    if(need >= INF) {
      cout << -1 << '\n';
      return;
    }
  }

  for(int i = N/2 - 1; i >= 0; --i)
    suffix_sum[i] += suffix_sum[i + 1];

  if(suffix_sum[0] > K) {
    cout << -1 << '\n';
    return;
  }

  for(int i = 0; i < N/2; ++i) {
    for(int dg = 9; dg >= 0; --dg) {
      int cost = d[S[i]-'0'][dg] + d[S[N-i-1]-'0'][dg];
      if(cost + suffix_sum[i + 1] <= K) {
        S[i] = S[N-i-1] = (char)(dg + '0');
        K -= cost;
        break;
      }
    }
  }

  if(N % 2) {
    for(int dg = 9; dg >= 0; --dg) {
      int cost = d[S[N/2]-'0'][dg];
      if(cost <= K) {
        S[N/2] = (char)(dg + '0');
        break;
      }
    }
  }

  cout << S << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int TT;
  cin >> TT;

  while(TT--) 
    test_case();

}