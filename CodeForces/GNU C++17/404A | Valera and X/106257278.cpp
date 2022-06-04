#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n][n];
  set<int> s;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      char ch;
      cin >> ch;
      a[i][j] = ch - 'a';
      if(i==j || i+j==n-1) {
        s.insert(a[i][j]);
      }
    }
  }
  if((int)s.size() > 1) {
    cout << "NO\n";
    return 0;
  }
  int x = *s.begin();
  s.clear();
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(i==j || i+j==n-1) {
      } else {
        s.insert(a[i][j]);
      }
    }
  }
  if((int)s.size() > 1) {
    cout << "NO\n";
    return 0;
  }
  int y = *s.begin();
  if(x == y) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
  return 0;
}