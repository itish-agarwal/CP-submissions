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
    int k = 2;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    //sort(a.begin(), a.end());
    sort(a, a + n);
    for(int i = n-1; i >= 2; i--) {
      int x = a[i] - k;
      int in = lower_bound(a, a + i, x) - a;
      if(i-in < 2) {
        continue;
      }
      int el = i - in;
      ans += (long long)el*((ll)el-1)/2;
    }
    cout << ans << '\n';
  }
  return 0;
}