#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  while(k--) {
    vector<int> a(n);
    for(auto& it : a) cin >> it;
    int p = 0;
    while(next_permutation(a.begin(), a.end())) {
      p++;
      if(p == 1) break;
    }
    for(int x : a) cout << x << " ";
    cout << '\n';
  }
}
  
