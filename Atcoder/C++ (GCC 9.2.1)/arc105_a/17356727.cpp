#include <bits/stdc++.h>

using namespace std;
int a, b, c, d;

int f(string now, int i) {
  if(i == 4) {
    int s1 = 0, s2 = 0;
    if(now[0] == '0') {
      s2 += a;
    } else {
      s1 += a;
    }
    
    if(now[1] == '0') {
      s2 += b;
    } else {
      s1 += b;
    }
    
    if(now[2] == '0') {
      s2 += c;
    } else {
      s1 += c;
    }
    
    if(now[3] == '0') {
      s2 += d;
    } else {
      s1 += d;
    }
    
    return s1 == s2;
  }
  
  return f(now + '0', i + 1) | f(now + '1', i + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c >> d;
  if(f("", 0)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
