#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int ans = 2e9;
    int pawn = -1;
    for(int i = 0; i < n; i++) {
      if(p[i] <= k) {
        if((k-p[i])%p[i] == 0) {
          if((k-p[i])/p[i] < ans) {
            ans = (k-p[i])/p[i];
            pawn = p[i];
          }
        }
      }
    }
    cout << pawn << '\n';
  }
  return 0;
}
