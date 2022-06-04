#include <bits/stdc++.h>
 
using namespace std;

void test_case() {
  int l, b;
  cin >> l >> b;
  cout << __gcd(l, b) << '\n';
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
