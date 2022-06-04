#include <bits/stdc++.h>

using namespace std;

int f(int a, int b) {
  if(a==0 || b==0) return 0;
  int mx = max(a, b);
  int mn = min(a, b);
  return mx/mn + f(mn, mx % mn);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b;
    cin >> a >> b;
    cout << f(a, b) << '\n';
  }
}