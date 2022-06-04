#include <bits/stdc++.h>

using namespace std;
const int nax = 1e5 + 55;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  vector<string> ret;
  for(int i = 1; i <= nax; i++) {
    string s = "";
    int n = i;
    while(n > 0) {
      s.push_back(n%2 + '0');
      n /= 2;
    }
    reverse(s.begin(), s.end());
    ret.push_back(s);
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int in = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << ret[in] << " ";
        in++;
      }
      cout << '\n';
    }
  }      
  return 0;
}
