#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  string S;

  cin >> N >> S;

  cout << (S[--N] != 'o' ? "No" : "Yes") << '\n';
}