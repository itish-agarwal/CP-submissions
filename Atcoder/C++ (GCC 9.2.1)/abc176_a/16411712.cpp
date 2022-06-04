#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, t;
  cin >> n >> x >> t;
  int g = n/x;
  if(x*g!=n) g++;
  cout<<g*t<<endl;
  return 0;
}
