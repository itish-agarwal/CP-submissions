#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int nax = 21;
int n, a[nax][nax];
int dp[nax][(1<<nax)];

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

int ways(int id, int mask) {
  //mask is for women that are paired;
  if(id==n) {
    return 1;
  }
  if(dp[id][mask] <= -1) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
      if(!(mask>>i & 1) && a[id][i]) {
        add_self(answer, ways(id+1, mask|(1<<i)));
      }
    }
    dp[id][mask] = answer;
  }
  return dp[id][mask];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << ways(0, 0) << '\n';
  return 0;
}
