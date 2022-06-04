#include <bits/stdc++.h>
 
using namespace std;
const int nax = 1e6 + 7;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    int l, b;
    cin >> l >> b;
    a[i] = min(l, b);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for(auto it : a) {
    if(it >= ans + 1) {
      ++ans;
    }
  }
  cout << ans << '\n';
}
  
                        