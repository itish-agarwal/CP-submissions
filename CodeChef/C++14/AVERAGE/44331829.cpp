#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto& it : a) cin >> it;
  sort(a.begin(), a.end());
  int ans = 0;
  for(auto it : a) {
    int l = 0, r = n - 1;
    while(l < r) {
      if(a[l]+a[r] == 2*it) {
        ++ans;
        break;
      } 
      if(a[l]+a[r] < 2*it) {
        ++l;
      } else {
        --r;
      }
    }
  }
  cout << ans << '\n';
}
