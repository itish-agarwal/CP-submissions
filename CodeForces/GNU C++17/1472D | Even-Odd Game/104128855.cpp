#include <bits/stdc++.h>
 
using namespace std;
#define int int64_t
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x;
    cin >> n;
    priority_queue<int> s0, s1;
    for(int i = 0; i < n; i++) {
      cin >> x;
      if(x % 2) {
        s1.push(x);
      } else {
        s0.push(x);
      }
    }
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
      if(i % 2) {
        //bobs turn
        if(s0.empty()) {
          b += s1.top();
          s1.pop();
        } else if(s1.empty()) {
          s0.pop();
        } else {
          int odd = s1.top();
          int even = s0.top();
          if(even > odd) {
            s0.pop();
          } else {
            b += s1.top();
            s1.pop();
          }
        }
      } else {
        //wants to take even
        if(s1.empty()) {
          a += s0.top();
          s0.pop();
        } else if(s0.empty()) {
          s1.pop();
        } else {
            
          int odd = s1.top();
          int even = s0.top();
          if(odd > even) {
            s1.pop();
          } else {
            a += s0.top();
            s0.pop();
          }
        }
      }
    }
    if(a > b) {
      cout << "Alice\n";
    } else if(b > a) {
      cout << "Bob\n";
    } else {
      cout << "Tie\n";
    }
  }
  return 0;
}