#include <bits/stdc++.h>
 
using namespace std;
 
int floor_div(int a, int b) {
  return a / b - ((a ^ b) < 0 && a % b != 0);
}
 
int ceil_div(int a, int b) {
  return a / b + ((a ^ b) > 0 && a % b != 0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T;
  cin >> T;
  while(T--) {
    int a, b;
    cin >> a >> b;
 
    set<int> vals;
 
    if((a + b) % 2 == 0) {
      int alice_serves = floor_div(a + b, 2), bob_serves = ceil_div(a + b, 2);
      for(int k1 = 0; k1 <= alice_serves; k1++) {
        int num = a - b + 2 * k1;
        int k2 = num / 2;
        if(k2 >= 0 && k2 <= bob_serves && 2 * k2 == num) {
          vals.insert(k1 + k2);
        }
      }
      for(int k2 = 0; k2 <= bob_serves; k2++) {
        int num = 2 * k2 - a + b;
        int k1 = num / 2;
        if(k1 >= 0 && k1 <= alice_serves && 2 * k1 == num) {
          vals.insert(k1 + k2);
        }
      }
    }
 
    else {
      int alice_serves = ceil_div(a + b, 2), bob_serves = floor_div(a + b, 2);
      //alice serves first;
      for(int k1 = 0; k1 <= alice_serves; ++k1) {
        int num = a - b - 1 + 2 * k1;
        int k2 = num / 2;
        if(k2 >= 0 && k2 <= bob_serves && 2 * k2 == num) {
          vals.insert(k1 + k2);
        }
      }
      for(int k2 = 0; k2 <= bob_serves; ++k2) {
        int num = 2 * k2 - a + b + 1;
        int k1 = num / 2;
        if(k1 >= 0 && k1 <= alice_serves && 2 * k1 == num) {
          vals.insert(k1 + k2);
        }
      }
 
      swap(alice_serves, bob_serves);
      //bob serves first;
      for(int k1 = 0; k1 <= alice_serves; ++k1) {
        int num = a - b + 1 + 2 * k1;
        int k2 = num / 2;
        if(k2 >= 0 && k2 <= bob_serves && 2 * k2 == num) {
          vals.insert(k1 + k2);
        }
      }
      for(int k2 = 0; k2 <= bob_serves; ++k2) {
        int num = 2 * k2 - a + b - 1;
        int k1 = num / 2;
        if(k1 >= 0 && k1 <= alice_serves && 2 * k1 == num) {
          vals.insert(k1 + k2);
        }
      }
    }
 
    cout << (int) vals.size() << '\n';
    for(int x : vals)
      cout << x << " ";
 
    cout << '\n';
  }
}