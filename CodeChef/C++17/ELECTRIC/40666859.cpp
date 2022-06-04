
#include <bits/stdc++.h>

using namespace std;
#define int int64_t 
const int nax = 1e3 + 44;

ostream& operator << (ostream& stream, const vector<int>& v) {
  for(int x : v) {
    stream << x << " ";
  }
  return stream;
}

//ostream& operator << (ostream& stream, const int *a) {
  //for(int i = 0; i < n; i++) {
    //stream << *(a + i) <<  " ";
  //}
  //return stream;
//}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, g = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      g = __gcd(g, a[i]);      
    }
    cout << g << " ";
    int cost = 0;
    for(int x : a) {
      cost += x/g;
    }
    cout << cost << '\n';
  }
  return 0;
}
    
    
    
    
