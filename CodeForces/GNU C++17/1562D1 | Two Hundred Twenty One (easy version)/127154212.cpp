#include <bits/stdc++.h>
 
using namespace std;
 
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
    cout << values[i] << (i < to ? ' ' : '\n');
}
int value(char x) {
  return x == '+' ? 1 : -1;
}
void test_case() {
  int N, Q;
  string S;
 
  cin >> N >> Q >> S;
 
  vector<int> preffix_sum(N);
  for(int i = 0; i < N; ++i) {
    int mul = (i % 2 ? -1 : 1);
    preffix_sum[i] = mul * (value(S[i])) + (i > 0 ? preffix_sum[i-1] : 0);
  }
 
  vector<int> b(N);
  for(int i = 0; i < N; ++i) {
    int before = (i > 0 ? preffix_sum[i-1] : 0);
    int after = preffix_sum[N-1] - preffix_sum[i];
    b[i] = before - after;
  }
 
  auto get_sign_variable_sum = [&](int l, int r) {
    return (l % 2 ? -1 : 1) * (preffix_sum[r] - (l > 0 ? preffix_sum[l-1] : 0));
  };
 
  for(int q = 0; q < Q; ++q) {
    int l, r;
    cin >> l >> r;
    --l, --r;
 
    int sum = get_sign_variable_sum(l, r);
    if(sum == 0) {
      cout << 0 << '\n';
    }
    else {
      cout << (l % 2 == r % 2 ? 1 : 2) << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T;
  cin >> T;
  while(T--)
    test_case();
}