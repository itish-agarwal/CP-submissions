#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, string>> ret(n);
  for(int i = 0; i < n; i++) {
    cin >> ret[i].second >> ret[i].first;
  }
  sort(ret.begin(), ret.end());
  cout << ret[n-2].second << '\n';
}