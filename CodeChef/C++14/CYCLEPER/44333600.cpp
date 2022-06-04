#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i]; 
    a[i] -= 1;
  }
  vector<vector<int>> ans;
  vector<int> vis(n);
  while(*min_element(vis.begin(), vis.end()) <= 0) {
    for(int i = 0; i < n; ++i) {
      if(!vis[i]) {
        vector<int> b{i};
        vis[i] = 1;
        int nxt = a[i];
        while(nxt != i) {
          b.push_back(nxt);
          vis[nxt] = 1;
          nxt = a[nxt];
        }
        b.push_back(i);
        ans.push_back(b);        
        break;
      }
    }
  }
  cout << (int) ans.size() << '\n';
  for(auto it : ans) {
    for(auto itt : it) {
      cout << itt + 1 << " " ;
    }
    cout << '\n';
  }
}
  
