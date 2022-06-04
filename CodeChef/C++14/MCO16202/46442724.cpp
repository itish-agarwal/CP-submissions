#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int N = 3e3 + 6;

int dp[N][N][2];

string s;
int n;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int rec(int i, int runs, int last) {
  if(i == n) {
    return runs == 0;
  }

  if(dp[i][runs][last] > -1) {
    return dp[i][runs][last];
  }

  int res = 0;
  if(s[i] == '?') {
    if(last == 0) {

      add_self(res, rec(i + 1, runs, last));
      if(runs > 0) { 
        // res += rec(i + 1, runs - 1, 1);
        add_self(res, rec(i + 1, runs - 1, 1));
      }
    } else {
      // res += rec(i + 1, runs, last);
      add_self(res, rec(i + 1, runs, last));
      if(runs > 0) {
        // res += rec(i + 1, runs - 1, 0);
        add_self(res, rec(i + 1, runs - 1, 0));
      }
    }
    return dp[i][runs][last] = res;
  }
  if(last == 0) {
    if(s[i] == '1') {
      // res += rec(i + 1, runs - 1, 1);
      add_self(res, rec(i + 1, runs - 1, 1));
    } else {
      // res += rec(i + 1, runs, last);
      add_self(res, rec(i + 1, runs, last));
    }
  } else {
    if(s[i] == '1') {
      // res += rec(i + 1, runs, last);
      add_self(res, rec(i + 1, runs, last));
    } else {
      // res += rec(i + 1, runs - 1, 0);
      add_self(res, rec(i + 1, runs - 1, 0));
    }
  }
  return dp[i][runs][last] = res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;

  n = s.size();

  memset(dp, -1, sizeof(dp));

  for(int r = 0; r < n; r++) {
    int ans = 0;
    if(s[0] == '?') {
      add_self(ans, rec(1, r, 1));
      add_self(ans, rec(1, r, 0));
      // ans += rec(1, r, 1);
      // ans += rec(1, r, 0);
    } else if(s[0] == '1') {
      ans += rec(1, r, 1);
    } else {
      ans += rec(1, r, 0);
    }
    cout << ans << " ";
  }
}

