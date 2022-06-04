#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int& x : a) cin >> x;
  for(int& x : b) cin >> x;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += a[i]*b[i];
  }
  if(ans==0) {
    cout << "Yes\n";
  } else cout << "No\n";
  return 0;
}
