#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string str;
    cin >> str;
    multiset<int> s;
    vector<int> cnt(26);
    for(char ch : str) {
      cnt[ch-'a']++;
    }
    for(int x : cnt) {
      if(x > 0) {
        s.insert(x);
      }
    }
    int res = 0;
    while(1) {
      if(s.empty()) {
        break;
      }
      if(s.size() == 1) {
        int x = *s.begin();
        res += x/3;
        break;
      }
      int most = *s.rbegin();
      int less = *s.begin();
      s.erase(s.find(most));
      s.erase(s.find(less));
      int take = min(most/2, less);
      if(take <= 0) {
        break;
      }
      res += take;
      most -= 2*take;
      less -= take;
      if(most > 0) {
        s.insert(most);
      } 
      if(less > 0) {
        s.insert(less);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
