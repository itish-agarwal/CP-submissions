#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  int mx = -2e9;

  int s = 0;

  while(N--) {
    int a;
    cin >> a;
    mx = max(mx, a);
    if(a >= 0) {
      s += a;
    }
  }

  if(mx < 0) {
    cout << mx << '\n';
    return 0;
  }

  cout << s << '\n';
}