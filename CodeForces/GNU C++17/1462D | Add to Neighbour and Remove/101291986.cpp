#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
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
 
bool solve() {
  int x;
  cin >> x;
  return false;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = n;
    vector<int> pre(n);
    pre[0] = a[0];
    for(int i = 1; i < n; i++) {
      pre[i] = pre[i-1] + a[i];
    }
    for(int i = 0; i < n; i++) {      
      int eq = pre[i];
      int pos = i, last = i+1;
      int check = eq;
      //check.insert(eq);
      if(pre.back() % eq == 0) {        
        for(int j = i+1; j < n; j++) {
          if(pre[j]-pre[last-1] == eq) {
            check += eq;
            pos += j - last;
            last = j + 1;
          }
        }
      }
      if(pos < ans && check==pre.back()) {
        ans = pos;
        //cout << eq << " " << pos << endl;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}