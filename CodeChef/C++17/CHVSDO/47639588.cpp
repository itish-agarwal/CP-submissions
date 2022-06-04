#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 7;
vector<int> spf(N);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  iota(spf.begin(), spf.end(), 0);
  for(int p = 2; p < N; p++) {
    if(spf[p] == p) {
      for(int j = p + p; j < N; j += p) {
        spf[j] = min(spf[j], p);
      }
    }
  }
  int L, R, S;
  cin >> L >> R >> S;
  vector<int> a;
  for(int i = L; i <= R; i++) {
    int x = i, n = 0;
    while(x > 1) {
      int p = spf[x];
      while(x%p == 0) {
        x /= p;
      }
      n += 1;
    }
    a.push_back(n);
  }

  auto add_self = [&](int& a, int b) {
    a += b;
    if(a >= mod) {
      a -= mod;
    }
  };

  vector<int> dp(S + 1);
  dp[0] = 1;
  for(int x : a) {
    for(int i = S - x; i >= 0; i--) {
      add_self(dp[i + x], dp[i]);
    }
  }

  cout << dp[S] << '\n';
}