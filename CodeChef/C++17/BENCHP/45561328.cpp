#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);  
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N, W, Wr;
    cin >> N >> W >> Wr;
    vector<int> A(N);
    map<int, int> freq;
    for(auto& a : A) {
      cin >> a;
      freq[a]++;
    }
    int can = Wr;
    for(auto it : freq) {
      int take = (it.second % 2 ? it.second - 1 : it.second);
      can += (it.first) * take;
    }
    // cout << can << endl;
    if(can >= W) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}