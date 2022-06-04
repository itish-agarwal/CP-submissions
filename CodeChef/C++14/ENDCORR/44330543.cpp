#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<int> s;
  for(int i = 0; i < n + m; ++i) {
    int c;
    cin >> c;
    if(c == -1) {
      cout << *s.rbegin() << '\n';
      s.erase(*s.rbegin());
    } else {
      s.insert(c);
    }
  }
}
