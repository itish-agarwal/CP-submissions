#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tt;
  cin >> tt;
  while(tt--) {
    int k;
    cin >> k;
    int g = __gcd(k, 100);
    cout << 100/g << '\n';
  }
}