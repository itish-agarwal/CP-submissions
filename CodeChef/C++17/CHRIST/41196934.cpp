#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int nax = 1e7 + 444;
vector<bool> ispr(nax, 1);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ispr[1] = false;
  for(int p = 2; p*p < nax; p++) {
    if(ispr[p]) {
      for(int i = p+p; i < nax; i += p) {
        ispr[i] = false;
      }
    }
  }
  vector<int> p;
  for(int i = 2; i < nax; i++) {
    if(ispr[i]) {
      p.push_back(i);
    }
  }
  int n;
  cin >> n;
  cout << n << " ";
  for(int i = 0; i < (n-1); i++) {
    cout << n*p[i] << " ";
  }
  cout << '\n';
  return 0;
}
