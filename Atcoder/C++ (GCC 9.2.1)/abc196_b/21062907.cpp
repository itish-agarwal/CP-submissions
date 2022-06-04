#include <bits/stdc++.h>
 
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for(int i = 0; i < (int)s.size(); ++i) {
    if(s[i] == '.') {
      cout << s.substr(0, i) << '\n';
      return 0;
    }
  }
  cout << s << '\n';
}
