#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    int i = 0, j = n - 1;
    int alice = 0, bob = 0;
 
    int z = 0;
    for(char c : s) {
      if(c == '0') {
        z++;
      }
    }
 
    while(i<j) {
      if(s[i] != s[j]) {
        bob++;
        z--;
      }
      i++;
      j--;
    }
    
    if(z % 2) {
      if(z == 1) {
        alice++;
      } else {
        alice += z / 2;
        bob += z - z / 2;
      }
    } else {
      if(z > 0) {
        alice += z / 2 + 1;
        bob += z / 2 - 1;
      }
    }
 
    if(alice < bob) {
      cout << "ALICE\n";
    } else if(bob < alice) {
      cout << "BOB\n";
    } else {
      cout << "DRAW\n";
    }
  }
  return 0;
}