#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    set<int> s;
    while(i <= j) {
      s.insert(a[i]*a[j]);
      i++;
      j--;
    }
    if((int)s.size() > 1) {
      cout << "-1\n";
    } else {
      int x = *s.begin();
      vector<int> has;
      for(int i = 2; i*i <= x; i++) {
        if(x%i == 0) {
          has.push_back(i);
          if(i*i != x) {
            has.push_back(x/i);
          }
        }
      }
      sort(has.begin(), has.end());
      if((int)has.size() == n) {
        bool ok = 1;
        for(int i = 0; i < n; i++) {
          if(has[i]!=a[i]) {
            cout << "-1\n";
            ok = false;
            break;
          }
        }
        if(ok) {
          cout << x << '\n';
        }
      } else {
        cout << "-1\n";
      } 
    }
  }
  return 0;
}
