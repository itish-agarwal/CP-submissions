#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n], b[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for(int i = 0; i <= (n-3); i++) {
    bool b1 = (a[i]==b[i]);
    bool b2 = (a[i+1]==b[i+1]);
    bool b3 = (a[i+2]==b[i+2]);
    if(b1&&b2&&b3) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
