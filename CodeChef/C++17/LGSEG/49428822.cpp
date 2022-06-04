#include <bits/stdc++.h>

using namespace std;
#define int long long

const int LOG = 22;

vector<int> far_max(const vector<int>& values, int K, int S) {
  int N = values.size();
  vector<int> res(N, N - 1);

  int i = 0, j = -1, sum = 0;
  
  while(i < N) {
    while(j+1 < N && sum + values[j+1] <= S) 
      sum += values[++j];

    sum -= values[i];
    res[i++] = j;
  }

  return res;
}
void test_case() {
  int N, K, S;
  cin >> N >> K >> S;

  vector<int> A(N);
  for(auto& a : A)
    cin >> a;

  vector<vector<int>> mat(LOG, vector<int> (N, N - 1));
  mat[0] = far_max(A, K, S);

  for(int j = 1; j < LOG; ++j) {
    for(int i = 0; i <= N - (1 << j); ++i) {
      if(mat[j-1][i] < N - 1)
        mat[j][i] = mat[j-1][mat[j-1][i] + 1];
    } 
  }

  int ans = K;

  for(int i = 0; i < N - 1; ++i) {
    int len = 0, l = i;
    for(int j = 0; j < LOG; ++j) {
      if(K & (1 << j) && l < N) {
        l = mat[j][l] + 1;
      }
    }
    ans = max(ans, l - i);
  }

  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  
  while(TT--) 
    test_case();
  
}