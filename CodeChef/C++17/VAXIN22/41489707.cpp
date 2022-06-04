#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int sum0, sum;

void op1(int x, int y) {
  int temp = 1;
  while(y > 0) {
    y--;
    temp *= x;
    //cout << temp << " " ;
    int cur = temp%100;
    cur /= 10;
    //cout << temp << " " << cur << '\n';
    sum0 += cur;
  }
}  

void operation1(int x, int y) {
  if(x==3 || x==5) {
    return;
  }
  if(x==4) {
    if(y==1) {
      return;
    }
    y--;
    y %= 4;
    if(y==0 || y==3) {
      return;
    } else {
      sum++;
    }
  } else {
    if(y <= 3) {
      return;
    }
    y -= 3;
    y %= 4;
    if(y==1) {
      sum++;
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while(q--) {
    int op ;
    cin >> op;
    if(op==1) {
      int x, y;
      cin >> x >> y;
      operation1(x, y);
    } else {
      cout << sum%2 << '\n';
    }
  }
  return 0;
}
