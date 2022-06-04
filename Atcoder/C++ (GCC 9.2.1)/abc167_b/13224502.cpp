#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a,b,c,k;
  cin >> a >> b >> c >> k;
  
  if(k <= a) {
    cout << k << "\n";
  }else if(k <= (a + b)) {
    cout << a << "\n";
  }else {
    cout << a - (k - (a + b)) << "\n";
  }
}