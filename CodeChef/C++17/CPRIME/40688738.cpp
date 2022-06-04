
#include <bits/stdc++.h>

using namespace std;
#define int int64_t 

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

const int nax = 1e5 + 55;
vector<bool> ispr(nax, 1);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ispr[1] = 0;
  for(int p = 2; p*p < nax; p++) {
    if(ispr[p]) {
      for(int i = p+p; i < nax; i += p) {
        ispr[i] = false;
      }
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    if(ispr[n]) {
      string s = to_string(n);
      string t = s;
      reverse(s.begin(), s.end());
      if(s == t) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
    
