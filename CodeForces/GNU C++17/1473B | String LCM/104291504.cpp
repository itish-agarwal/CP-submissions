#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int l = n*m/__gcd(n, m);
    string S = "", T = "";
    for(int i = 0; i < l/n; i++) {
      S += s;
    }
    for(int i = 0; i < l/m; i++) {
      T += t;
    }
    if(S!=T) S = "-1";
    cout << S << '\n';
  }
  return 0;
}