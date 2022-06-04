#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
vector<string> ret;

int ceil(int a, int b) {
  return (a + b - 1) / b;
}
void f(int i, int l, string s) {
  if(i == l) {
    ret.push_back(s + s);
    return;
  }
  for(char ch = '0'; ch <= '9'; ch++) {
    string t = s;
    t.push_back(ch);
    f(i + 1, l, t);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string t = to_string(n);
  for(int l = 1; l <= ceil( (int)t.size(), 2 ); l++) {
    for(char ch = '1'; ch <= '9'; ch++) {
      string s = "";
      s.push_back(ch);
      f(1, l, s);
    }
  }
  vector<int> foo;
  for(string s : ret) {
    foo.push_back(stoll(s));
  }
  cout << upper_bound(foo.begin(), foo.end(), n) - foo.begin() << '\n';
  return 0;
}
