#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int nax = 1e4 + 55;
vector<string> fib(nax);

string add(string a, string b) {
  if(a.size() < b.size()) {
    string t = a;
    a = b;
    b = t;
  }
  int j = a.size()-1;
  for(int i=b.size()-1; i>=0; i--, j--) {
    a[j]+=(b[i]-'0');
  }
  for(int i=a.size()-1; i>0; i--) {
    if(a[i] > '9') {
      int d = a[i]-'0';
      a[i-1] = ((a[i-1]-'0') + d/10) + '0';
      a[i] = (d%10)+'0';
    }
  }
  if(a[0] > '9') {
    string k;
    k+=a[0];
    a[0] = ((a[0]-'0')%10)+'0';
    k[0] = ((k[0]-'0')/10)+'0';
    a = k+a;
  }
  return a;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fib[1] = "0";
  fib[2] = "1";
  for(int i = 3; i < nax; i++) {
    fib[i] = add(fib[i-1], fib[i-2]);
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int in = 1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= i; j++) {
        cout << fib[in] << " " ;
        in++;
      }
      cout << '\n';
    }
  }
  return 0;
}
