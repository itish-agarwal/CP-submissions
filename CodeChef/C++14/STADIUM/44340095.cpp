#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ret(n);
  for(int i = 0; i < n; ++i) {
    cin >> ret[i].first >> ret[i].second;
  }
  sort(ret.begin(), ret.end());
  vector<int> b;
  for(auto it : ret) b.push_back(it.first);
  vector<int> dp(n, 1);
  for(int i = n-2; i >= 0; --i) {
    int k = ret[i].first + ret[i].second + 1;
    int in = lower_bound(b.begin(), b.end(), k) - b.begin();
    if(in < n) {
      dp[i] = dp[in] + 1;
    }
    dp[i] = max(dp[i], dp[i + 1]);
  }
  cout << dp[0] << '\n';
}
