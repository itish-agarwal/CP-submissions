#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, p;
  cin >> l >> p;
  p--;
  //assume banana
  int fruit = 1;
  int ll = l;
  while(ll > 1) {
    if(l % 2) {
      if(p % 2 == 0) {
        fruit ^= 1;
      }
    } else {
      if(p % 2) {
        fruit ^= 1;
      }
    }
    --ll;
    p /= 2;
  }
  if(fruit == 0) {
    cout << "Banana\n";
  } else {
    cout << "Apple\n";
  }
}