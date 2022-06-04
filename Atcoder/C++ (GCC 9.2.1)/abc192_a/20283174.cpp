#include <bits/stdc++.h>


using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if(n%100==0) {
    cout << 100 << '\n';
  } else {
    int k = n/100;
    k++;
    cout << k*100 - n << '\n';
  }
}
