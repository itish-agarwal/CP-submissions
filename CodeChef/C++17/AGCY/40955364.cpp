#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q;
    cin >> n >> q;
    pair<int, int> have[q];
    vector<long long> b(n + 5);
    for(int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      have[i] = make_pair(l, r);
      b[l]++;
      b[r+1]--;
    }
    for(int i = 1; i <= n+4; i++) {
      b[i] += b[i-1];
    }
    for(int i = 0; i < q; i++) {
      b[have[i].second+1] -= (long long)(have[i].second-have[i].first+1);
    }
    for(int i = 1; i <= n; i++) {
      b[i] += b[i-1];
      cout << b[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
