#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  int c = n / 100;
  if(100*c != n) {
    c += 1;
  }

  cout << c << '\n';

}