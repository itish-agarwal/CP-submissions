#include <bits/stdc++.h>
 
using namespace std;
 
bool in_range(int i, int N) {
  return i >= 0 && i < N;
}
 
bool valid(int l1, int r1, int l2, int r2, int N) {
  return in_range(l1, N) && in_range(r1, N) && in_range(l2, N) && in_range(r2, N) && (r1 - l1 + 1 >= N/2) && (r2 - l2 + 1 >= N/2);
}
 
int bin(string s) {
  int n = s.size(), res = 0;
  reverse(s.begin(), s.end());
  for(int i = 0; i < n; ++i) 
    if(s[i] == '1')
      res += 1 << i;
 
  return res;
}
 
void test_case() {
  int N;
  string S;
 
  cin >> N >> S;
 
  int first_zero = -1, last_zero = -1;
 
  // if(N <= 7) {
  //   for(int l1 = 0; l1 < N; l1++) {
  //     for(int r1 = l1; r1 < N; r1++) {
  //       for(int l2 = 0; l2 < N; l2++) {
  //         for(int r2 = l2; r2 < N; r2++) {
  //           if(((l1^l2) || (r1^r2)) && valid(l1, r1, l2, r2, N)) {
  //             int t = bin(S.substr(l1, r1-l1+1));
  //             int w = bin(S.substr(l2, r2-l2+1));
  //             if((t == 0 && w == 0) || (w > 0 && t % w == 0)) {
  //               cout << l1 + 1 << " " << r1 + 1 << " " << l2 + 1 << " " << r2 + 1 << '\n';
  //               return;
  //             }
  //           }
  //         }
  //       }
  //     }
  //   }
  // }
 
  for(int i = 0; i < N; ++i) {
    if(S[i] == '0') {
      if(first_zero == -1) 
        first_zero = i;
      last_zero = i;
    }
  }
 
  if(first_zero == -1) {
    int l1 = 0, r1 = N - 2, l2 = 1, r2 = N - 1;
    cout << l1 + 1 << " " << r1 + 1 << " " << l2 + 1 << " " << r2 + 1 << '\n';
    return;
  }
 
  int l1 = first_zero, r1 = N - 1, l2 = first_zero + 1, r2 = N - 1;
  if(valid(l1, r1, l2, r2, N)) {
    cout << l1 + 1 << " " << r1 + 1 << " " << l2 + 1 << " " << r2 + 1 << '\n';
    return;
  }
 
  l1 = 0, r1 = last_zero, l2 = 0, r2 = last_zero - 1; 
  cout << l1 + 1 << " " << r1 + 1 << " " << l2 + 1 << " " << r2 + 1 << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T;
  cin >> T;
  while(T--)
    test_case();
}