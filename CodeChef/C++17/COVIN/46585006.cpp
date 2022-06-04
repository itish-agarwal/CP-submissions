#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  const int nax = 100;
  vector<long long> fib(nax);
  fib[1] = 1;

  for(int i = 2; i < nax; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    cout << fib[n + 1] << '\n';
  }
}