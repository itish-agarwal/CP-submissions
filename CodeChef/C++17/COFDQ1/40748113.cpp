
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

//ABCDEFGHIJKLMNOPQRSTUVWXYZ

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, k;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> k;
  for(int i = 0; i <= n-k; i++) {
    vector<int> b;
    for(int j = i; j < i + k; j++) {
      b.push_back(a[j]);
    }
    sort(b.begin(), b.end());
    if(k % 2) {
      cout << b[k/2] << " ";
    } else {
      int x = b[k/2];
      int y = b[(k/2)-1];
      double m = (x + y)*1.0;
      m /= (2*1.0);
      printf("%0.1lf ", m);
    }
  }
  cout << '\n';
  return 0;
}
