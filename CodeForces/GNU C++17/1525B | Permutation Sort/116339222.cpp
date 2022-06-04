#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
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
 
    vector<int> b = a;
    sort(a.begin(), a.end());
 
    if(is_sorted(b.begin(), b.end())) {
      cout << "0\n";
    } else {
      if(b[0]==n && b[n-1]==1) {
        cout << "3\n";
      } else {
        if(b[0]==1 || b[n-1]==n) {
          cout << "1\n";
        } else {
          cout << "2\n";
        }
      }
    }
  }
}