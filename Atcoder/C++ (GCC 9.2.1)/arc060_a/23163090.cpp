#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int N, T, A[100];
long long dp[51][51][3000];

long long rec(int i, int j, int sum) {
  if(i == N) {
    return sum == T*j && j > 0;
  }
  if(dp[i][j][sum] == -1) {
    long long ans = rec(i + 1, j, sum);
    ans += rec(i + 1, j + 1, sum + A[i]);
    dp[i][j][sum] = ans;
  }
  return dp[i][j][sum];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> T;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0, 0) << '\n';
}