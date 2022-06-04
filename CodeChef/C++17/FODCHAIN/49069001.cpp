#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int E, K;
    cin >> E >> K;
    int level = 0;
    while(E > 0) {
      level++;
      E /= K;
    }
    cout << level << '\n';
  }
}