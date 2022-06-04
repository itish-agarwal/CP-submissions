#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N;
    cin >> N;
    vector<int> A(N);
    int mn = 2e9 + 7;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
      mn = min(mn, A[i]);
    }
    vector<bool> is_min(N, 0);
    for(int i = 0; i < N; i++) {
      if(A[i] == mn) {
        is_min[i] = 1;
      }
      A[i] -= mn;
    }
    int my_index = ((mn - 1) % N + 1) % N;
    int minute = 1;
    while(1) {
      if(is_min[my_index] || A[my_index] == 0) {
        cout << my_index + 1 << '\n';
        break;
      }
      my_index = (my_index + 1) % N;
      A[my_index] = max(0, A[my_index] - minute);
      minute++;
    }
  }
}
