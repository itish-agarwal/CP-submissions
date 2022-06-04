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
template <class T>
struct SparseTable {
public:
  int N;
  vector<int> compute;
  vector<vector<T>> tab;
 
  T merge(const T& a, const T& b) {
    return min(a, b);
  }
 
  SparseTable(const vector<T>& values) {
    int N = values.size();
    compute.resize(N + 1);
    for(int i = 2; i <= N; ++i) 
      compute[i] = compute[i / 2] + 1;
 
    const int log = 32 - __builtin_clz(N);
    tab.resize(log);
 
    tab[0] = values;
    for(int j = 1; j < log; ++j) {
      tab[j].resize(N - (1 << j) + 1);
      for(int i = 0; i <= N - (1 << j); ++i)
        tab[j][i] = merge(tab[j-1][i], tab[j-1][i + (1 << (j-1))]);
    }
  }
 
  T query(int L, int R) {
    int j = compute[R - L + 1];
    return merge(tab[j][L], tab[j][R - (1 << j) + 1]);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<long long> C(N);
 
  for(auto& c : C)
    cin >> c;
  
  vector<long long> preffix_sum(N);
  preffix_sum[0] = C[0];
 
  for(int i = 1; i < N; ++i) 
    preffix_sum[i] = preffix_sum[i-1] + (i % 2 ? -C[i] : C[i]);
 
  SparseTable<long long> st(preffix_sum);
 
  auto get_sum = [&](int l, int r) {
    return preffix_sum[r] - (l > 0 ? preffix_sum[l-1] : 0);
  };
 
  long long ans = 0;
 
  for(int i = 0; i < N; i += 2) {
    for(int j = i + 1; j < N; j += 2) {
      if(j == i + 1) {
        ans += min(C[i], C[j]);
      }
 
      else {
        long long mn = st.query(i + 1, j - 1) - preffix_sum[i];
        if(mn <= 0) {
          long long sum = get_sum(i + 1, j - 1);
          if(sum >= 0) {
            long long min_take_open = abs(mn);
            long long max_take_closed = min_take_open + sum;
            if(min_take_open <= C[i] && max_take_closed <= C[j]) {
              long long add = min({max_take_closed, C[i] - min_take_open + 1});
              ans += min(C[i] - min_take_open, C[j] - max_take_closed) + 1; 
            }
          }
          else {
            long long min_take_open = max(abs(mn), abs(sum));
            long long max_take_closed = min_take_open + sum;
            if(min_take_open <= C[i] && max_take_closed >= 0 && max_take_closed <= C[j]) {
              long long add = min({max_take_closed, C[i] - min_take_open + 1});
              ans += min(C[i] - min_take_open, C[j] - max_take_closed) + 1;
            }
          }
        } 
        else {
          long long sum = get_sum(i + 1, j - 1);
          if(sum >= 0) {
            long long min_take_closed = max(mn, sum);
            long long max_take_open = min_take_closed - sum;
            if(min_take_closed <= C[j] && max_take_open >= 0 && max_take_open <= C[i]) {
              int add = min({max_take_open, C[j] - min_take_closed + 1});
              ans += min(C[i] - max_take_open, C[j] - min_take_closed) + 1;
            }
          } 
          else {
 
          }         
        }
      }
    }
  } 
 
  cout << ans << '\n';
}