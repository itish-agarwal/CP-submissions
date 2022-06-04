#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> id;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    id.emplace_back(a, i);
  }
  sort(id.begin(), id.end());
  vector<int> ans(N, K / N);
  int left = K % N;
  for(int i = 0; i < left; i++) {
    ans[id[i].second]++;
  }
  for(int i = 0; i < N; i++)
    cout << ans[i] << '\n';
  return 0;
}