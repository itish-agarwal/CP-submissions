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
 
    vector<int> A(N + 1);
    for(int i = 1; i <= N; ++i)
      cin >> A[i];
 
    int iters = 0;
 
    auto func = [&](int i) {
      if(A[i] > A[i+1]) {
        swap(A[i], A[i+1]);
      }
    };
 
    while(!is_sorted(A.begin(), A.end())) {
      if(iters % 2) {
        for(int i = 2; i <= N - 1; i += 2) {
          func(i);
        }
      }
      else {
        for(int i = 1; i <= N - 2; i += 2) {
          func(i);
        }
      }
      iters += 1;
    }
 
    cout << iters << '\n';
  }
}