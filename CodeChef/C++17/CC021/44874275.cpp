#include <bits/stdc++.h>

using namespace std;
const int nax = 5e4 + 7;
vector<int> prime(nax, 1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  prime[0] = prime[1] = 0;
  for(int i = 2; i < nax; i++) {
    if(prime[i]) {
      for(int j = i + i ; j < nax; j += i) {
        prime[j] = 0;
      }
    }
  }
  for(int i = 1; i < nax; i++) {
    prime[i] += prime[i - 1];
  }
  int n, L, R;
  cin >> L >> R >> n;
  vector<int> cnt(n);
  for(int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    if(l>R || L>r) {
      continue;
    }
    int LL , RR;
    if(L <= l) {
      LL = l;
      RR = min(R, r);
    } else {
      LL = L;
      RR = min(R, r);
    }
    cnt[i] = prime[RR] - prime[LL-1];
  }
  int mx = *max_element(cnt.begin(), cnt.end());
  if(!mx) {
    cout << "-1\n";
    return 0;
  }
  for(int i = 0; i < n; i++) {
    if(cnt[i] == mx) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}