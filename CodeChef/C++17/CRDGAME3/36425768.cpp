#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int pc, pr;
    cin >> pc >> pr;
    int t1 = pc/9, t2 = pr/9;
    if(pc%9) t1++;
    if(pr%9) t2++;
    if(t1 < t2) {
      cout << 0 << " " << t1 << '\n';
    } else {
      cout << 1 << " " << t2 << '\n';
    }
  }
  return 0;
}
    
    
    
    
    
    
    
    
    
    
    
