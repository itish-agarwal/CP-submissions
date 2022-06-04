#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
   
  int n = s.size();
  if(t.substr(0, n) != s){
    cout << "No\n";
  }else {
    cout << "Yes\n";
  }
}