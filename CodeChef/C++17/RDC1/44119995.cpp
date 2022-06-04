#include <bits/stdc++.h>
 
using namespace std;
  
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    map<int, int> mp;
    while(n--) {
      int a;
      cin >> a;
      mp[a]++;
    }
    set<int> s;
    for(auto it : mp) {
      s.insert(it.second);
    }
    if((int)mp.size() == (int)s.size()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }    
  }
}
