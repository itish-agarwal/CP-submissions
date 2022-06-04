#include <bits/stdc++.h>
 
using namespace std;
bool is_prime[505];
 
void test_case() {
  int N;
  cin >> N;
 
  string S;
  cin >> S;
    
  for(int i = 0; i < N; ++i) {
    int x = S[i] - '0';
    if(!is_prime[x]) {
      cout << 1 << '\n' << x << '\n';
      return;
    }
  }
 
  for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j < N; ++j) {
      int x = 10 * (S[i] - '0') + S[j] - '0';
      if(!is_prime[x]) {
        cout << 2 << '\n' << x << '\n';
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  memset(is_prime, true, sizeof(is_prime));
  is_prime[0] = is_prime[1] = false;
 
  for(int p = 2; p < 505; ++p) {
    if(is_prime[p]) {
      for(int j = 2 * p; j < 505; j += p) {
        is_prime[j] = false;
      }
    }
  }
 
  int T;
  cin >> T;
 
  while(T--) 
    test_case();
}