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
  int n;
  cin >> n;
  string s;
  cin >> s;
  if(s == "2020") {
    return 1;
  }
  
  string a = s.substr(0, 1) + s.substr(n-3);
  string b = s.substr(0, 2) + s.substr(n-2);
  string c = s.substr(0, 3) + s.substr(n-1);
  
  string d = s.substr(0, 4);
  string e = s.substr(n-4);
  
  if(a=="2020" || b=="2020" || c=="2020" || d=="2020" || e=="2020") {
    return 1;
  }
  return 0;  
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int tt;
  cin >> tt;
  while(tt--) {
    if(solve()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}