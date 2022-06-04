#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int f(int a[], int n) {
  if(n == 1) {
    return 0;
  }
  if(n == 2) {
    if(a[0] > a[1]) {
      return 1;
    }
    return 0;
  }
  int a1[n], a2[n];
  int mid = n/2;
  for(int i = 0; i < mid; i++) {
    a1[i] = a[i];
  }
  int n1 = mid;
  int n2 = n - mid;
  for(int i = mid; i < n; i++) {
    a2[i-mid] = a[i];
  }
  int ans = f(a1, n1) + f(a2, n2);
  for(int i = 0; i < n2; i++) {
    int x = a2[i];
    int in = upper_bound(a1, a1 + n1, x) - a1;
    if(in>=0 && in<n1) {
      ans += n1 - in;
    }
  }  
  int i = 0, j = 0, k = 0;
  while(i<n1 && j<n2) {
    if(a1[i] < a2[j]) {
      a[k] = a1[i];
      i++;
      k++;
    } else {
      a[k] = a2[j];
      j++;
      k++;
    }
  }  
  while(i < n1) {
    a[k] = a1[i];
    i++;
    k++;
  }
  while(j < n2) {
    a[k] = a2[j];
    j++;
    k++;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << f(a, n) << '\n';
  }
  return 0;
}
