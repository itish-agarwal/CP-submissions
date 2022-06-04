#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<int> fact(19);

int ncr(int n, int r) {
  if(r==0 || r==n) {
    return 1;
  }
  return (n*ncr(n-1, r-1))/r;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for(int i = 1; i < 19; i++) {
    fact[i] = i*fact[i-1];
  }
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    set<int> t;
    int n = s.size();
    int ans = fact[n];
    for(char ch : s) {
      t.insert(ch);
    }
    bool kar = (t.find('k')!=t.end() && t.find('a')!=t.end() && t.find('r')!=t.end());
    bool shi = (t.find('s')!=t.end() && t.find('h')!=t.end() && t.find('i')!=t.end());
    
    if(kar && shi) {
      int has = 0;
      for(int before = 0; before <= n-3; before++) {
        has += ncr(n-3, before)*fact[before]*fact[n-before-3];
      }
      ans -= has;  
      ans -= has;
      int add = 0;
      //ans += has both 'kar' and 'shi'
      for(int before = 0; before <= n-6; before++) {
        for(int middle = 0; middle <= n-before-6; middle++) {
          int k = ncr(n-6, before)*ncr(n-before-6, middle)*fact[before]*fact[middle]*fact[n-before-middle-6];
          add += k + k;
        }
      }
      ans += add;      
    } else if(kar && !shi) {      
      int has = 0;
      for(int before = 0; before <= n-3; before++) {
        has += ncr(n-3, before)*fact[before]*fact[n-before-3];
      }
      ans -= has;      
    } else if(!kar && shi) {
      int has = 0;
      for(int before = 0; before <= n-3; before++) {
        has += ncr(n-3, before)*fact[before]*fact[n-before-3];
      }
      ans -= has;
    } else {
    }
    cout << ans << '\n';    
  }
  return 0;
}
