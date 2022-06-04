#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  int open = 0;
  for(char ch : S) {
    open += ch == '(';
    cout << open << " ";
  }
  cout << '\n';
  return 0;
}