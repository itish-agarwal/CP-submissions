#include <bits/stdc++.h>
 
using namespace std;
const int nax = 1e5 + 77;
vector<bool> pr(nax, 1);
int a[6][nax];

int main() {
  pr[1] = 0;
  for(int p = 2; p*p < nax; p++) {
    if(pr[p]) {
      for(int i = p+p; i < nax; i += p) {
        pr[i] = false;
      }
    }
  }
  for(int i = 2; i < nax; ++i) {
    int k = 0;
    for(int j = 1; j*j <= i; ++j) {
      if(i%j == 0) {
        int d1 = j, d2 = i/j;
        if(pr[d1]) ++k;
        if(d1!=d2 && pr[d2]) ++k;
      }
    }
    if(k <= 5) {
      a[k][i] = 1;
    }
  }
  for(int k = 0; k <= 5; ++k) {
    for(int i = 1; i < nax; ++i) {
      a[k][i] += a[k][i-1];
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << a[k][r] - a[k][l-1] << '\n';
  }
}
