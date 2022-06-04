#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1e6 + 7;
vector<int> spf(MAX_N);

vector<int> prime_factors(int n) {
  vector<int> res;
  while(n > 1) {
    int p = spf[n], tt = 0;
    while(n % p == 0) {
      n /= p;
      tt++;
    }
    if(tt % 2) {
      res.push_back(p);
    }
  }
  return res;
}
void run_case() {
  int N;
  cin >> N;

  long long ans = (long long)N * (N - 1) / 2;
  map<vector<int>, int> freq;
  for(int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    vector<int> factors = prime_factors(a);
    ans -= freq[factors];
    freq[factors] += 1;
  }

  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  iota(spf.begin(), spf.end(), 0);
  for(int p = 2; p < MAX_N; p++) {
    if(spf[p] == p) {
      for(int j = p; j < MAX_N; j += p) {
        spf[j] = min(spf[j], p);
      }
    }
  }

  int tt;
  cin >> tt;

  while(tt--)
    run_case();
}