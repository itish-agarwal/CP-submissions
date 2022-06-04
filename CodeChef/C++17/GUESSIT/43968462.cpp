#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test() {
  for(int i = 1; i <= 2000; ++i) {
    cout << i*i << "\n";
    cout.flush();
    int q;
    cin >> q;
    if(q == 1) {
      return;
    } 
  }
}
int main() {
  int T;
  cin >> T;
  while(T--) {
    test();
  }
}
