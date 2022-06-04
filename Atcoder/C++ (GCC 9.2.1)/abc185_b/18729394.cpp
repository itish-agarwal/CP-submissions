#include <bits/stdc++.h>

using namespace std;
#define int long long 

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
  
  int a, b, c, d;
  
  int cap, m, t;
  cin >> cap >> m >> t;
  int level = cap;
  int last = 0;
  vector<pair<int, int>> ret;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ret.push_back({a, b});
  }
  
  for(int i = 0; i < m; i++) {
    
    int a = ret[i].first;
    int b = ret[i].second;
    
    int dec = a - last;
    if(level - dec <= 0) {
      cout << "No\n";
      return 0;
    }
    
    level -= dec;
    level += (b-a);
    level = min(level, cap);
    last = b;
  }  
  int dec = t - last;
  if(level <= dec) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }  
  return 0;
}
