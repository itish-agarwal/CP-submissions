#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int>> a, b;
  for(int i = 0; i < n + n; ++i) {
    int r;
    cin >> r;
    if(i >= n) {
      b.emplace_back(r, i - n);
    } else {
      a.emplace_back(r, i);
    }
  }
  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());

  map<int, vector<int>> mp;
  multiset<int> s;

  for(int i = 0; i < n; ++i) {
    mp[get<0>(b[i])].emplace_back(i);
  }
  for(auto it : mp) s.insert(it.first);

  vector<int> answer(n);
  int win = 0;

  for(auto itt : a) {
    int r = get<0>(itt), in = get<1>(itt);
    auto it = s.upper_bound(r);
    if(it == s.begin()) {
      int sorted_idx = mp[*it].back();
      mp[*it].pop_back();
      if(mp[*it].empty()) {
        s.erase(s.find(*it));
      }
      answer[in] = get<1>(b[sorted_idx]);
    } else {
      it--;
      int sorted_idx = mp[*it].back();
      mp[*it].pop_back();
      if(mp[*it].empty()) {
        s.erase(s.find(*it));
      }
      answer[in] = get<1>(b[sorted_idx]);
      win++;
    }   
  }
  cout << win << '\n';
  for(auto it : answer) cout << it + 1 << '\n';
}

