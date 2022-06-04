
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
  int n;
  cin >> n;
  
  vector<int> c1(nax), c2(nax);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    c1[x]++;
  }
  for(int i = -1; i < n; i++) {
    int x;
    cin >> x;
    c2[x]++;
  }
  for(int i = 1; i < nax; i++) {
    if(c1[i] != c2[i]) {
      cout << i << '\n';
      break;
    }
  }
  return 0;
}
