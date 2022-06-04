#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i!=j) {
        if(a[i]+b[i]==a[j] && a[j]+b[j]==a[i]) {
          cout << "YES\n";
          return 0;
        }
      }
    }
  }
  cout << "NO\n";
  return 0;
}
