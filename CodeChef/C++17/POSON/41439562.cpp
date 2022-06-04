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
    int n = s.length();
    int k0 = 0, k1 = 0;
    for(int i = 0; i < n; i++) {
      if(s[i]=='a' && t[i]=='b') {
        k0++;
      } else if(s[i]=='b' && t[i]=='a') {
        k1++;
      }
    }
    if(k0!=k1) {
      cout << "No\n";
    } else {
      cout << "Yes " << k0 << '\n';
    }
  }
  return 0;
}
