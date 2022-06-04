#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, h;
  cin >> m >> h;
  if(h % m) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}