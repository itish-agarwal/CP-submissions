#include <bits/stdc++.h>

using namespace std;
const string findd = "chokudai";
string S;
int M, N;

const int mod = 1e9 + 7;
vector<vector<int>> dp;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int rec(int i, int j) {
  if(i == N) {
    return j == M;
  }
  if(dp[i][j] > -1) 
    return dp[i][j];

  int res = rec(i + 1, j);

  if(j < M && S[i] == findd[j])
    add_self(res, rec(i + 1, j + 1));

  return dp[i][j] = res;  
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> S;
  N = S.size();
  M = findd.size();

  dp = vector<vector<int>> (N + 1, vector<int> (M + 1, -1));
  cout << rec(0, 0) << '\n';

  return 0;
}