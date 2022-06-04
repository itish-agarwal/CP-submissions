#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, A, B;
    cin >> a >> b >> A >> B;
    cout << A/a + B/b << '\n';
  }
}