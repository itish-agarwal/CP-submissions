#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int i, j, can = 0;
    if(n % 2) {
      i = n/2 - 1;
      j = n/2 + 1;
    } else {
      i = n/2 - 1;
      j = n/2;
    }      
    priority_queue<int> s;
    if(n % 2) {
      can += a[n/2];
    }
    while(i >= 0) {
      s.push(a[i]);
      s.push(a[j]);
      can += s.top();
      s.pop();
      i--;
      j++;
    }
    if(can >= X) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
      
