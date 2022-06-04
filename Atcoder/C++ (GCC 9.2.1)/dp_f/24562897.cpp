#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> len(n + 1, vector<int> (m + 1));
  vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>> (m + 1, {-1, -1}));
  for(int i = n - 1; i >= 0; --i) {
    for(int j = m - 1; j >= 0; --j) {
      if(s[i] == t[j]) {
        len[i][j] = 1 + len[i+1][j+1];
        dp[i][j] = {i + 1, j + 1};
        continue;
      }
      int best = max(len[i+1][j], len[i][j+1]);
      len[i][j] = best;
      if(len[i+1][j] == best) {
        dp[i][j] = {i + 1, j};
      }
      else {
        dp[i][j] = {i, j + 1};
      }
    }
  }
  string ans = "";
  int i = 0, j = 0;
  while(i < n && j < m) {
    if(s[i] == t[j]) {
      ans.push_back(s[i]);
    }
    auto x = dp[i][j];
    i = x.first;
    j = x.second;
  }
  cout << ans << '\n';
}