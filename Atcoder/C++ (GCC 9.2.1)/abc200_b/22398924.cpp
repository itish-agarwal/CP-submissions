#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long n, k;
  cin >> n >> k;

  while(k--) {
    if(n % 200) {
      n *= 1000LL;
      n += 200;
    } else {
      n /= 200;
    }
  }

  cout << n << '\n';
}
