#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n, m; ll k;
  cin >> n >> m >> k;
  int a[n], b[m];
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < m; ++i) cin >> b[i];  
  long long pre_b[m], pre_a[n];
  pre_b[0] = b[0];
  pre_a[0] = a[0];
  for(int i = 1; i < m; ++i) {
    pre_b[i] = (ll)pre_b[i - 1] + (ll)b[i];
  }
  for(int i = 1; i < n; ++i) {
    pre_a[i] = (ll)pre_a[i - 1] + (ll)a[i];
  }  
  int answer = 0;
  for(int count = 0; count <= n; ++count) {
    long long check = (count == 0 ? 0 : pre_a[count - 1]);
    if(k >= check) {
      long long left = k - check;
      //find max number of books u can read with k == left;
      int pos = 0;
      if(pre_b[0] > left) {        
      } else if(pre_b[m - 1] <= left) {
        pos = m;
      } else {
        int L = 0;
        int R = m - 1;
        while(L <= R) {
          int mid = (L + R) / 2;          
          if(pre_b[mid] <= left) {
            if(mid < (m - 1) && pre_b[mid + 1] > left) {
              pos = mid + 1;
            }
            L = mid + 1;
          } else {
            if(mid > 0 && pre_b[mid - 1] <= left) {
              pos = mid;
            }
            R = mid - 1;
          }
        }
      }
      pos += count;
      answer = max(answer, pos);
    }
  }
  cout << answer << '\n';
  return 0;
}
