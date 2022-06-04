#include <bits/stdc++.h>

using namespace std;
int N, T[400], limit;

int dp[101][100006], vis[101][100006];
//find largest sum less than or equal to limit
int rec(int i, int sum) {
  if(i == N)
    return sum;
  //not take
  if(vis[i][sum])
    return dp[i][sum];
  int ans = rec(i + 1, sum);
  if(sum + T[i] <= limit) {
    ans = max(ans, rec(i + 1, sum + T[i]));
  }
  vis[i][sum] = 1;
  return dp[i][sum] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  int lo = 0, hi = 0, total = 0;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
    lo = max(lo, T[i]);
    total += T[i];
    hi += T[i];
  }
  int ans = hi;
  while(lo <= hi) {
    int mid = (lo + hi)/2;
    limit = mid;
    for(int i = 0; i <= N; i++) {
      for(int j = 0; j <= total; j++)
        vis[i][j] = 0;
    }
    int sum1 = rec(0, 0);
    if(total - sum1 <= limit) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << '\n';
}