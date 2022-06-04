#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
 
    vector<pair<int, int>> caves;
    for(int i = 0; i < N; ++i) {
      int K;
      cin >> K;
      int pass = -1;
 
      for(int j = 0; j < K; ++j) {
        int a;
        cin >> a;
        pass = max(pass, a - j);
      }
      caves.emplace_back(pass, -K);
    } 
 
    sort(caves.begin(), caves.end());
 
    int ans = 0, store = 0;
    for(auto [e, l] : caves) {
      ans = max(ans, e - store);
      store -= l;
    }
 
    cout << ++ans << '\n';
  }   
}