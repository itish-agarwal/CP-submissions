#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;

  int Y = S.back() - '0';

  int L = S.size();
  S = S.substr(0, L - 2);

  if(Y <= 2) {
    cout << S << "-\n";
  }

  else if(Y <= 6) {
    cout << S << '\n';
  }

  else {
    cout << S << "+\n";
  }
}