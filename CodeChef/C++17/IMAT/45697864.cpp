#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;
  while(tt--) {

    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> A(N, vector<int> (M));
    
    for(auto& aa : A)
      for(auto& a : aa) 
        cin >> a;

    if(N > M) {
      vector<vector<int>> x(M, vector<int> (N));
      for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
          x[i][j] = A[j][i];
        }
      }
      swap(N, M);
      A = x;
    }

    auto add_self = [&](int& a, int b) {
      a += b;
      if(a >= mod) {
        a -= mod;
      }
    };

    int answer = 0;

    for(int mask = 0; mask < (1 << N); mask++) {

      vector<int> x;
      for(int j = 0; j < M; j++) {
        int s = 0;
        for(int i = 0; i < N; i++) {
          if(mask & (1 << i)) {
            s += A[i][j];
          }
        }
        x.push_back(s);
      }

      if(M <= 25) {

        vector<int> d, e;
        int half = M / 2;
        for(int i = 0; i < half; i++) {
          d.push_back(x[i]);
        }
        for(int i = half; i < M; i++) {
          e.push_back(x[i]); 
        }

        vector<int> L(1 << half);
        for(int m = 0; m < (1 << half); m++) {
          for(int i = 0; i < half; i++) {
            if(m & (1 << i)) {
              L[m] += d[i];
            }
          }
        }

        sort(L.begin(), L.end());
        vector<int> continuous(1 << half, 1);
        for(int i = 1; i < (1 << half); i++) {
          if(L[i] == L[i - 1]) {
            continuous[i] = continuous[i - 1] + 1;
          } 
        }

        int hl = e.size();
        for(int m = 0; m < (1 << hl); m++) {
          int already = 0;
          for(int i = 0; i < hl; i++) {
            if(m & (1 << i)) {
              already += e[i];
            }
          }
          int need = B - already;
          int in = upper_bound(L.begin(), L.end(), need) - L.begin() - 1;

          if(in >= 0 && in < (1 << half)) {
            if(L[in] == need) {
              add_self(answer, continuous[in]);
            }
          }
        }
      } else {

        vector<int> dp(B + 1);
        dp[0] = 1;
        for(int a : x) {
          for(int i = B - a; i >= 0; i--) {
            add_self(dp[i + a], dp[i]);
          }
        }
        add_self(answer, dp[B]);
      }
    }

    cout << answer << '\n';
  }
}