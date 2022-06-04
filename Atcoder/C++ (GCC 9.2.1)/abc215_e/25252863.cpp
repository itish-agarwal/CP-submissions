#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1e5 + 7;

vector<int> spf(MAX_N);

vector<int> prime_factors(int X) {
  vector<int> res;
  while(X > 1) {
    int p = spf[X];
    res.push_back(p);
    while(X % p == 0) {
      X /= p;
    }
  }

  return res;
}
template <class T> 
ostream& operator << (ostream& stream, const vector<T>& values) {
  for(T v : values) 
    cout << v << " ";

  return stream;
}
template <class T>
void print_vector(const vector<T>& values, int from = -1, int to = -1) {
  if(from < 0) from = 0;
  if(to < 0) to = int(values.size()) - 1;

  for(int i = from; i <= to; ++i) 
    cout << values[i] << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  iota(spf.begin(), spf.end(), 0);
  for(int p = 2; p < MAX_N; ++p) {
    if(spf[p] == p) {
      for(int j = 2 * p; j < MAX_N; j += p) {
        spf[j] = min(spf[j], p);
      }
    }
  }

  int N, M;
  cin >> N >> M;

  vector<bool> present(MAX_N);
  for(int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    vector<int> factors = prime_factors(a);
    for(auto& p : factors) {
      present[p] = true;
    }
  }

  vector<int> ans;
  for(int i = 1; i <= M; ++i) {
    vector<int> factors = prime_factors(i);
    int cnt = 0;
    for(auto& p : factors) {
      cnt += present[p];
    }
    if(cnt == 0) {
      ans.push_back(i);
    }
  }

  cout << (int) ans.size() << '\n';
  print_vector(ans);
}