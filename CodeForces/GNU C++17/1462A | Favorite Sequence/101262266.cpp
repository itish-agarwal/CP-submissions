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
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n+1), ans(n+1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for(int i = 1; i <= (n+1)/2; i++) {
      ans[2*i-1] = a[i];
    }
    for(int i = 1; i <= n/2; i++) {
      ans[2*i] = a[n-i+1];
    }
    for(int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }cout<<'\n';
  }
  return 0;
}