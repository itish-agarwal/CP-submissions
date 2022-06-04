#include <bits/stdc++.h>
 
using namespace std;
#define int long long
vector<int> ret;

void rec(int i, string s, vector<bool>& taken) {
  if(i >= 11) return;
  ret.push_back(stoll(s));
  for(int i = 1; i <= 9; ++i) {
    if(!taken[i]) {
      string t = s;
      t.push_back(i + '0');
      taken[i] = true;
      rec(i + 1, t, taken);
      taken[i] = false;
    }
  }
}
signed main(){
  vector<bool> taken(10);
  for(int i = 1; i <= 9; ++i) {
    string s;
    s.push_back(i + '0');
    taken[i] = 1;
    rec(1, s, taken);
    taken[i] = 0;
  }
  sort(ret.begin(), ret.end());
  int n;
  cin >> n;
  auto it = upper_bound(ret.begin(), ret.end(), n);
  if(it == ret.end()) {
    cout << "0\n";
  } else {
    cout << *it << '\n';
  }
}
