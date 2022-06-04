#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    set<int> s;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    if((int)s.size() == 1) {
      if(x % a[0] == 0 && x / a[0] <= n) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
          cout << a[i] << " " ;
        }
        cout << '\n';
      }
    } else {
      sort(a.begin(), a.end());
      int s = 0;
      for(int y : a) s += y;
      if(s == x) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        s = 0;
        for(int i = 0; i < n; i++) {
          s += a[i];
          if(s == x) {
            if(a[i] == a[n - 1]) {
              int tmp = a[0];
              a[0] = a[n - 1];
              a[n - 1] = tmp;
            } else {
              int tmp = a[i];
              a[i] = a[n - 1];
              a[n - 1] = tmp;
            }
            break;
          }
        }
        for(int y : a) {
          cout << y << " ";
        }
        cout << '\n';
      }
    }
  }
}