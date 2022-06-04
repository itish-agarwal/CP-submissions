#include <bits/stdc++.h>

using namespace std;
const int nax = 1e4 + 44;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = n / 4;
    vector<int> cnt(nax);
    while(n--) {
      int l;
      cin >> l;
      cnt[l]++;
    }
    int s = 0;
    for(int x : cnt) {
      s += x/2;
    }
    cout << min(ans, s/2) << ' ';
  }
  cout << '\n';
  return 0;
}
