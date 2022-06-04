#include <bits/stdc++.h>
 
using namespace std;
 
int inv(vector<int> a) {
  int ans = 0;
  int n = a.size();
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(a[i] > a[j]) ++ans;
    }
  }
  return ans;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), ans(n + 1);
    int sub = 1;
    for(int i = 1; i <= n; i++) {
      if(i <= k) {
        a[i] = i;
      } else {
        a[i] = k - sub;
        sub++;
      }
    }
    if(n % 2) {
      int diff = k - n/2;
      int size = n - k;
      int start = -1;
      start += 2*(diff-1);
      for(int i = 0; i <= start; i++) {
        cout << a[i+1] << " ";
      }
      for(int i = start+size+1; i < n; i++) {
        cout << a[i+1] << " ";
      }
    } else {
      int diff = k - n/2;
      int size = n - k;
      int start = 0;
      start += 2*(diff-1);
      for(int i = 0; i <= start; i++) {
        cout << a[i+1] << " ";
      }
      for(int i = start+size+1; i < n; i++) {
        cout << a[i+1] << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
    