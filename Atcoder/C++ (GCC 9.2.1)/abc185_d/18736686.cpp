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

int ncr(int n, int r) {
  if(r==0 || r==n) {
    return 1;
  }
  int ans = ncr(n-1, r-1);
  ans *= n;
  return ans/r;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a;
  a.push_back(0);
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  a.push_back(n+1);
  sort(a.begin(), a.end());
  vector<int> b;
  for(int i = 1; i < (int)a.size(); i++) {
    int l = a[i] - a[i-1] - 1;
    if(l > 0) {
      b.push_back(a[i] - a[i-1] - 1);
    }
  }
  if(b.empty()) {
    cout << "0\n";
    return 0;
  }
  sort(b.begin(), b.end());

  int k = b[0];
  int ans = 0;
  for(int x : b) {
    ans += x/k;
    if(x % k) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
  
