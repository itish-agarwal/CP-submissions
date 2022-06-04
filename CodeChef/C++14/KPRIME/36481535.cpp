#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 10;
vector<bool> is_prime(nax, 1);
int marked[nax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  is_prime[1] = 0;
  for(int p = 2; p < nax; p++) {
    if(is_prime[p]) {
      for(int j = p; j < nax; j += p) {
        is_prime[j] = 0;
        marked[j]++;
      }
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    for(int i = a; i <= b; i++) {
      if(marked[i]==k) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
  
  
