#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d, t, s;
  cin >> d >> t >> s;
  if(t*s < d) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  return 0;
}
