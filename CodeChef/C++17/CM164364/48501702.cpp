#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, a, x;
    cin >> n >> x;
    map<int, int> freq;
    for(int r = 0; r < n; r++) {
      cin >> a;
      freq[a]++;
    }
    cout << min(n - x, (int)freq.size()) << '\n';
  }
  return 0;
}