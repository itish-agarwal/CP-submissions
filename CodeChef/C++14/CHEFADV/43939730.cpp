#include <bits/stdc++.h>
 
using namespace std;
string yes = "Chefirnemo";
string no = "Pofik";

void test_case() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  n--;
  m--;
  //do not use +1
  if(n%x==0 && m%y==0) {
    cout << yes << '\n';
    return;
  }
  //use +1
  if(n>0 && m>0) {
    n--;
    m--;
    if(n%x==0 && m%y==0) {
      cout << yes << '\n';
      return;
    }
  }
  cout << no << '\n';
}
int main() {
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
}
