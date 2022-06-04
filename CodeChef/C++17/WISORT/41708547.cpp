#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  //cout << a << " " << b << '\n';
  for(int i = 0; i < min((int)a.size(), (int)b.size()); i++) {
    if(a[i] > b[i]) {
      return false;
    } else if(b[i] > a[i]) {
      return true;
    }
  }
  if((int)a.size() > (int)b.size()) {
    return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int nr = 1; nr <= tt; nr++) {
    int n;
    cin >> n;
    vector<string> ret;
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      ret.emplace_back(s);
    }
    sort(ret.begin(), ret.end(), cmp);
    cout << "Case " << nr << ":\n";
    for(string s : ret) {
      cout << s << '\n';
    }
  }
  return 0;
}
