#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;
  if(a==b || b==c || a==c) {
    if(a==b) {
      cout<<c<<'\n';
    } else if(b==c) {
      cout<<a<<'\n';
    } else {
      cout<<b<<'\n';
    }
  } else {
    cout<<0<<'\n';
  }
}