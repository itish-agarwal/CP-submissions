
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
  set<int> s;
  int n;
  cin >> n;
  while(n--) {
    int x;
    cin >> x;
    s.insert(x);
  }
  for(int x : s) {
    cout << x << " ";
  }
  cout << '\n';
  return 0;
}

