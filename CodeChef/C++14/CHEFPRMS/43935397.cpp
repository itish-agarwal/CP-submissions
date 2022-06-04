#include <bits/stdc++.h>
 
using namespace std;

bool isprime(int n) {
  if(n == 1) return 0;
  if(n == 2) return 1;
  for(int p = 2; p < n; p++) {
    if(n%p == 0) {
      return 0;
    }
  }
  return 1;
}
bool semi_prime(int n) {
  for(int a = 2; a < n; ++a) {
    if(n%a == 0) {
      int b = n / a;
      if(isprime(a) && isprime(b) && a!=b) {
        return 1;
      }
    }
  }
  return 0;
}
void test_case() {
  int n;
  cin >> n;
  for(int a = 1; a < n; ++a) {
    int b = n - a;
    if(semi_prime(a) && semi_prime(b)) {
      //cout << a << " " << b << '\n';
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";    
}  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
}
