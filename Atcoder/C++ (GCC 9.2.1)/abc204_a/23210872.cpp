#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  if(x == y) 
    cout << x << '\n';
  else 
    cout << 3 - x - y << '\n';
}