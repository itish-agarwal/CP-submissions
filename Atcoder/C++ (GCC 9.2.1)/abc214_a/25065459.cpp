#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if(n <= 125) {
    cout << 4 << '\n';
  }
  else if(n <= 211) {
    cout << 6 << '\n';
  }
  else {
    cout << 8 << '\n';
  }
}