#include <bits/stdc++.h>

using namespace std;
#define int long long
//Usage -> vector<int> a, cout << a << '\n'
ostream& operator << (ostream& stream, const vector<int>& v) {
  for(auto x : v) stream << x << " ";
  return stream;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for(int i = n - 1; i >= 0; --i) {

    vector<int> ret;
    for(int j = 1; j <= i; j++) {
      ret.push_back(max(0LL, a[j]-a[j-1]));
    }
    sort(ret.rbegin(), ret.rend());

    if(ret.size()<x) {
      cout<<i<<'\n';
      return 0;
    }
 
    int s = 0;
    for(int j = x; j < ret.size(); ++j) {
      s += ret[j];
    }

    if(s<=k) {
      cout<<i<<'\n';
      return 0;
    }
  }
}