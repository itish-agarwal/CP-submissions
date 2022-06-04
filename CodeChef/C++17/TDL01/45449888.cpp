#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, X, h;
  cin >> N >> X;
  while(N--) {
    cin >> h;
    X += h;
  }
  if(X <= 24) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}