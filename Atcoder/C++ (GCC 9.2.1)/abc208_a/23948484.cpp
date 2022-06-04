#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B;
  cin >> A >> B;
  if(B >= A && B <= 6 * A) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}