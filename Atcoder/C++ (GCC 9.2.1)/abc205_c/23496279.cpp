#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long A, B, C;
  cin >> A >> B >> C;
  if(C % 2 == 0) {
    A *= A;
    B *= B;
  }
  cout << (A > B ? '>' : (A < B ? '<' : '=')) << '\n';
  return 0;
}