#include <bits/stdc++.h>

using namespace std;
const int N = 1e7 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> is_prime(N, 1);
  for(int p = 2; p < N; p++){
    if(is_prime[p]) {
      for(int j = p + p; j < N; j += p) {
        is_prime[j] = 0;
      }
    }
  }

  vector<int> pr;
  for(int p = 2; p < N; p++){
    if(is_prime[p]) 
      pr.push_back(p);
  }
  
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int K = pr[n - 1];
    int x = 0;
    if(K%4 == 1) {
      x = 1;
    } else if(K%4 == 2) {
      x = K + 1;
    } else if(K%4 == 3) {
      x = 0;
    } else {
      x = K;
    }
    cout << x << '\n';
  }
}