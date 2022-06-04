#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N, M, K;
    cin >> N >> M >> K;
    map<int, int> mp;
    while(K--) {
      int L;
      cin >> L;
      if(L >= 1 && L <= N) {
        mp[L]++;
      }
    }
    vector<int> ans;
    for(int i = 1; i <= N; i++) {
      if(mp[i] > 1) {
        ans.push_back(i);
      }
    }
    cout << (int)ans.size() << " ";
    for(int user : ans) {
      cout << user << " ";
    }
    cout << '\n';
  }
}