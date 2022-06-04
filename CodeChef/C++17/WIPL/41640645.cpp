#include <bits/stdc++.h>

using namespace std;
const int nax = 4e3 + 1;
const int inf = 2e9 + 7;
int a[nax], n, K;

//rec(i, S) gives the least height >= S using last i boxes;
int dp[nax][nax];

int rec(int i, int sum) {
  if(i==n) {
    if(sum >= K) return sum;
    return inf;
  }
  if(sum >= K) {
    return sum;
  }
  if(dp[i][sum] <= -1) {
    int answer = rec(i+1, sum);
    if(sum < K) {
      answer = min(answer, rec(i+1, sum + a[i]));
    }
    dp[i][sum] = answer;
  }
  return dp[i][sum];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n >> K;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    sort(a, a + n);
    vector<int> post(n+1);
    for(int i = n-1; i >= 0; i--) {
      post[i] = post[i+1] + a[i];
    }
    int answer = -1;
    for(int i = n-1; i >= 0; i--) {
      if(rec(i, 0) < inf) {
        if(post[i] - rec(i, 0) >= K) {
          answer = n - i;
          break;
        }
      }
    }
    cout << answer << '\n';
  }
  return 0;
}
