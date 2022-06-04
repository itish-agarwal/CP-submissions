#include <bits/stdc++.h>

using namespace std;
#define int long long

int power(int a, int b) {
  if(b == 0) {
    return 1;
  }
  int res = power(a, b/2);
  res *= res;
  if(b % 2) {
    res *= a;
  }
  return res;
}
bool is(string s) {
  int n = stoi(s);
  int l = s.size();
  int sum = 0;
  for(char ch : s) {
    int d = ch - '0';
    sum += power(d, l);
  }
  return sum == n;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    if(is(s)) {
      cout << "FEELS GOOD\n";
    } else {
      cout << "FEELS BAD\n";
    }
  }
  return 0;
}
