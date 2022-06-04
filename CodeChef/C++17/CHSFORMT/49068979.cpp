#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int a, b;
    cin >> a >> b;
    if(a + b < 3) {
      cout << 1 << '\n';
    }
    else if(a + b <= 10) {
      cout << 2 << '\n';
    }
    else if(a + b <= 60) {
      cout << 3 << '\n';
    }
    else {
      cout << 4 << '\n';
    }
  }
}