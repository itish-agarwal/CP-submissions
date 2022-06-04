#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string t;
    cin >> t;
    stack<char> s;
    for(char ch : t) {
      if(s.empty()) {
        s.push(ch);
        continue;
      } 
      if(ch==s.top()) {
        s.pop();
      } else {
        s.push(ch);
      }
    }
    cout << (int)s.size() << '\n';
  }
  return 0;
}
