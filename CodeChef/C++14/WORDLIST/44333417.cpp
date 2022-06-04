#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n;
  set<string> ret;
  getline(cin, s);
  while(n--) {
    getline(cin, s);
    string x = "";
    for(auto ch : s) {
      if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) {
        x += tolower(ch);
      } else {
        if((int) x.size()) {
          ret.insert(x);
        }
        x = "";
      }
    }
    if((int) x.size()) ret.insert(x);
  }
  cout << (int) ret.size() << '\n';
  for(auto it : ret) cout << it << '\n';
}
