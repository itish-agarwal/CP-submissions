#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

int power(int a, int b) {
  if(b == 0) return 1;
  int res = power(a, b/2);
  res = (res*res) % mod;
  if(b % 2) {
    res = (res*a) % mod;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> ret;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ret.emplace_back(s);
  }
  int l = ret[0].size();
  int c = 0;
  for(int i = 0; i < l; i++) {
    char ch = ret[0][i];
    bool ok = 1;
    for(string s : ret) {
      if(s[i]!=ch) {
        ok = 0;
        break;
      }
    }
    if(!ok) {
      c++;
    } else {
      if(ret[0][i]=='2') {
        ++c;
      }
    }     
  }
  cout << power(2LL, c) << '\n';
  return 0;
}
