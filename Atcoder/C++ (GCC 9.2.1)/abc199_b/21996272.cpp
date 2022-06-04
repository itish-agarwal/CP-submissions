#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, a;
  cin >> N;
  int l = -1, r = 100006;
  for(int i = 0; i < N; i++) {
    cin >> a;
    l = max(l, a);
  }
  for(int i = 0; i < N; i++) {
    cin >> a;
    r = min(r, a);
  }
  cout << max(0, r - l + 1) << endl;
}