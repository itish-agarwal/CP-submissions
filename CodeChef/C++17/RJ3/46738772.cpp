#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;
  while(tt--) {
    long long n;
    cin >> n;
    int r = 0;
    while(n>0) {
      r += n%2;
      n /= 2;
    }
    cout << r << '\n';
  }
}