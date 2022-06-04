
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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x, q;
    cin >> x >> q;
    while(q--) {
      int op, i;
      cin >> op;
      if(op == 1) {
        cin >> i;
        --i;
        if((x>>i) & 1) {
          cout << "ON\n";
        } else {
          cout << "OFF\n";
        }
      } else if(op == 2) {
        cin >> i;
        --i;
        x |= (1<<i);
      } else if(op == 3) {
        cin >> i;
        --i;
        if((x>>i) & 1) {
          x ^= (1<<i);
        }
      } else {
        int p, q;
        cin >> p >> q;
        --p; --q;
        int pbit = ((x>>p) & 1);
        int qbit = ((x>>q) & 1);
        if(!pbit && qbit) {
          x |= (1<<p);
          x ^= (1<<q);
        } else if(pbit && !qbit) {
          x ^= (1<<p);
          x |= (1<<q);
        } 
      }
      //cout << x << endl;
    }
  }
  return 0;
}
