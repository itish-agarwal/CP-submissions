#include <bits/stdc++.h>

using namespace std;
void test_case() {
  int n;
  cin >> n;
  set<int> s;
  while(n--) {
    int h;
    cin >> h;
    if(h>0) {
      s.insert(h);
    }
  }
  cout << (int)s.size() << '\n';
  return;
}  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    test_case();
  }
}
