#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector<int> A(N);
 
    for(auto& a : A)
      cin >> a;
 
    set<int> odd, even;
    for(int i = 0; i < N; ++i) {
      if(A[i] % 2) {
        odd.insert(i);
      }
      else {
        even.insert(i);
      }
    }
 
    int more = max((int) odd.size(), (int) even.size());
    int less = (int) odd.size() + (int) even.size() - more;
 
    if(more > (N + 1) / 2) {
      cout << -1 << '\n';
    } 
 
    else {
 
      long long ans = 0;
 
      if(N % 2 == 0) {
        int oddd = 0, evenn = 1;
 
        for(int i = 0; i < N; ++i) {
          if(A[i] % 2) {
            ans += max(0, i - oddd);
            oddd += 2;
          }
 
          else {
            ans += max(0, i - evenn);
            evenn += 2;
          }
        }
        long long x = ans;
 
        ans = 0;
        oddd = 1;
        evenn = 0;
 
        for(int i = 0; i < N; ++i) {
          if(A[i] % 2) {
            ans += max(0, i - oddd);
            oddd += 2;
          }
 
          else {
            ans += max(0, i - evenn);
            evenn += 2;
          }
        }
        ans = min(ans, x);
      }
 
      else {
        long long c = 0;
 
        if((int) odd.size() > (int) even.size()) {
          int oddd = 0, evenn = 1;
          for(int i = 0; i < N; ++i) {
            if(A[i] % 2) {
              c += max(0, i - oddd);
              oddd += 2;
            }
 
            else {
              c += max(0, i - evenn);
              evenn += 2;
            }
          }
        } 
 
        else {
          int oddd = 1, evenn = 0;
          for(int i = 0; i < N; ++i) {
            if(A[i] % 2) {
              c += max(0, i - oddd);
              oddd += 2;
            }
 
            else {
              c += max(0, i - evenn);
              evenn += 2;
            }
          } 
        }
 
        ans = c;
      }
 
      cout << ans << '\n';
    }
  }
}