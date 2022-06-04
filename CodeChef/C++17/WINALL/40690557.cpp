#include <bits/stdc++.h>

using namespace std;
#define a "Me"
#define b "Grinch"

bool isPrime(int n) {
  if(n == 1) {
    return false;
  } if(n == 2) {
    return true;
  }
  for(int i = 2; i*i <= n; ++i) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  if(n == 1) {
    cout << b << '\n';
    return;
  } if(n == 2) {
    cout << a << '\n';
    return;
  } if(n & 1) {
    cout << a << '\n';
    return;
  }
  int nn = n;
  while(nn%2 == 0) {
    nn /= 2;
  }
  if(nn == 1) {
    cout << b << '\n';
    return;
  }  
  n /= 2;
  if(isPrime(n) && n >= 3) {
    cout << b << '\n';
    return;
  }
  cout << a << '\n';
  return;
}

int main() {
  int tt;
  cin >> tt;
  while(tt--) {
    solve();
  }
  return 0;
}
