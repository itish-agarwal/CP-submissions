
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
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  int res = 0;
  int end = n-1;
  bool x = 1, y = 1;
  for(int i = 0; i < n; i++) {
    if(a[i]>1) {
      x = 0;
      break;
    }
  }
  for(int i = 0; i < m; i++) {
    if(b[i]>1) {
      y = 0;
      break;
    }
  }
  if(x && y) {
    cout << "0\n";
    return 0;
  }
  for(int i = 0; i < m; i++) {
    int lo = 0, hi = end;
    int ans = -1;
    while(lo <= hi) {
      int mid = (lo+hi)/2;
      if(a[mid] > b[i]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
        ans = mid;
      }
    }     
    if(ans <= -1) {
      res += end+1;
    } else {
      end = ans;
      res += end;      
      a[end] = b[i];
    }
  }
  cout << res << '\n';
  return 0;
}