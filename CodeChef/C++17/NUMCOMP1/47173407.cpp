#include <bits/stdc++.h>

using namespace std;
const int nax = 1e7 + 6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<bool> pr(nax, true);
  for(int p = 2; p < nax; p++) {
    if(pr[p]) {
      for(int j = p + p; j < nax; j += p) {
        pr[j] = false;
      }
    }
  }
  vector<int> a, all;
  for(int p = 2; p < nax; p++) {
    if(pr[p]) {
      a.push_back(p + p);
      all.push_back(p);
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    if(n == 2) {
      cout << 1 << '\n';
    } else if(n == 3) {
      cout << 2 << '\n';
    } else {
      int ll = upper_bound(a.begin(), a.end(), n) - a.begin();
      int rr = upper_bound(all.begin(), all.end(), n) - all.begin() - 1;
      cout << rr - ll + 2 << '\n';
    }
  }
}