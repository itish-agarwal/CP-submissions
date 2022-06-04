#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;
  while(tt--) {
    int A, B;
    cin >> A >> B;
    if(A > B) {
      cout << "A\n";
    } else {
      cout << "B\n";
    }
  }
}