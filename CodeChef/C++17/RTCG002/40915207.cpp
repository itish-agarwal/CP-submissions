#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int cal = 0;
  for(char ch : s) {
    if(ch=='D') {
      cal += 238;
    } else if(ch=='T') {
      cal += 244;
    } else if(ch=='M') {
      cal += 138;
    } else if(ch=='B') {
      cal += 279;
    } else cal += 186;
  }
  cout << cal/50 << "\n" << (cal%50)/5 << "\n" << 2*((cal%50)%5) << "\n";
  return 0;
}
