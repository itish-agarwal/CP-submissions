#include <bits/stdc++.h>

using namespace std;

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
  
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << min({a, b, c, d}) << '\n';
  
  
  
  
  
  
  return 0;
}
