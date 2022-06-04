#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a;
  for(int len = 1; len <= 30; ++len) {
    string s = "";
    int k = 0;
    while((int) s.size() <= 30) {
      if(k % 2 == 0) {
        s += string(len, '1');
      }    
      else {
        s += string(len, '0');
      }
      k++;
      if((int) s.size() <= 30) {
        int x = 0;
        string t = s;
        reverse(t.begin(), t.end());
        for(int i = 0; i < (int) s.size(); i++) {
          x += (1 << i) * (t[i] == '1' ? 1 : 0);
        }
        a.push_back(x);
      }
    }
  }
  sort(a.begin(), a.end());
  int tt;
  cin >> tt;
  while(tt--) {
    int l, r;
    cin >> l >> r;
    int ans = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;
    l--;
    ans -= upper_bound(a.begin(), a.end(), l) - a.begin() - 1;
    cout << ans << '\n';
  }
}