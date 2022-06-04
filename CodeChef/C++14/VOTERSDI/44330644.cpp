#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n1, n2, n3, a;
  cin >> n1 >> n2 >> n3;
  map<int, int> mp;
  for(int i = 0; i < n1; ++i) {
    cin >> a;
    mp[a]++;
  }
  for(int i = 0; i < n2; ++i) {
    cin >> a;
    mp[a]++;
  }
  for(int i = 0; i < n3; ++i) {
    cin >> a;
    mp[a]++;
  }
  vector<int> ans;
  for(auto it : mp) {
    if(it.second >= 2) {
      ans.push_back(it.first);
    }
  }
  sort(ans.begin(), ans.end());
  cout << (int) ans.size() << '\n';
  for(auto it : ans) cout << it << '\n';
}
