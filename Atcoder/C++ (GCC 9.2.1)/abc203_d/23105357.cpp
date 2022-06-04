#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<vector<int>> A(N + 1, vector<int> (N + 1));
  int lo = 2e9+7, hi = 0, ans;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> A[i][j];
      hi = max(hi, A[i][j]);
      lo = min(lo, A[i][j]);
    }
  }
  ans = hi;
  auto ceil = [&](int x, int y) {
    return (x + y - 1) / y;
  };
  int P = ceil(K*K, 2);
  while(lo <= hi) {
    int mid = (lo + hi)/2;
    vector<vector<int>> sum(N + 1, vector<int> (N + 1));
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        sum[i][j] = A[i][j] <= mid;
      }
    }
    for(int i = 1; i <= N; i++) {
      for(int j = 0; j <= N; j++) {
        sum[i][j] += sum[i - 1][j];
      }
    }
    for(int i = 0; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        sum[i][j] += sum[i][j - 1];
      }
    }
    bool ok = false;
    for(int i = K; i <= N; i++) {
      for(int j = K; j <= N; j++) {
        int count = sum[i][j] - sum[i - K][j] - sum[i][j - K] + sum[i - K][j - K];
        if(count >= P) {
          ok = true;
          break;
        }
      }
    }
    if(ok) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}