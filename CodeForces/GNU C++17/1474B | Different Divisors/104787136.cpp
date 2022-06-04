#include <bits/stdc++.h>
 
using namespace std;
const int nax = 1e6 + 55;
vector<bool> ispr(nax, 1);
vector<int> pr;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ispr[1] = 0;
  for(int p = 2; p*p < nax; p++) {
    if(ispr[p]) {
      for(int i = p+p; i < nax; i += p) {
        ispr[i] = 0;
      }
    }
  }
  for(int i = 2; i < nax; i++) {
    if(ispr[i]) {
      pr.emplace_back(i);
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int d;
    cin >> d;
    int l = d + 1;
    int in = lower_bound(pr.begin(), pr.end(), l) - pr.begin();
    long long b = pr[in];
    l = b + d;
    in = lower_bound(pr.begin(), pr.end(), l) - pr.begin();
    long long c = pr[in];
    cout << b*c << '\n';
  }
  return 0;
}