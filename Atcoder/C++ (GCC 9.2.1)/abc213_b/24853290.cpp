#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for(int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    a.emplace_back(s, i + 1);
  }
  sort(a.begin(), a.end());
  cout << a[n-2].second << '\n';
}