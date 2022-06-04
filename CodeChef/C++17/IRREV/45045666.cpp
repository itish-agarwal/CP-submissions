#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  // cout << a << " " << b << endl;
  if(a==0 || b==0) return a + b;
  long long more = max(a, b), less = min(a, b);
  return gcd(more % less, less);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    long long a, b;
    cin >> a >> b;
    if(gcd(a, b) == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}