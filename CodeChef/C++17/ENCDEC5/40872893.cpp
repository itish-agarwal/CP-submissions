
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
    int n, x;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> x;
    for(int i = 1; i < n; i += 2) {
      int tmp = a[i];
      a[i] = a[i-1];
      a[i-1] = tmp;
    }
    for(int i = 0; i < n; i++) {
      a[i] += (a[i] % 3);
    }
    sort(a.begin(), a.end());
    int in = upper_bound(a.begin(), a.end(), x) - a.begin();
    int greater = -1;
    if(in>=0 && in<n) {
      greater = a[in];
    }
    in = lower_bound(a.begin(), a.end(), x) - a.begin() - 1;
    int lower = -1;
    if(in>=0 && in<n) {
      lower = a[in];
    }
    cout << lower << " " << greater << '\n';
  }
  return 0;
}
