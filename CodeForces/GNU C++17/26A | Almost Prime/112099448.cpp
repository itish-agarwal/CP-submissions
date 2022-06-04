#include <bits/stdc++.h>
 
using namespace std;
const int nax = 3007;
 
bool is_pr(int n) {
 if(n == 1) return 0;
 if(n == 2) return 1;
 for(int i = 2; i*i <= n; ++i) {
  if(n%i == 0) {
   return false;
  }
 }
 return true;
}
bool almost_pr(int n) {
 int c = 0;
 for(int i = 1; i <= n; ++i) {
  if(n%i == 0 && is_pr(i)) {
   c++;
  }
 }
 return c == 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
   if(almost_pr(i)) {
    ++ans;
   }
  }
  cout << ans << '\n';
}