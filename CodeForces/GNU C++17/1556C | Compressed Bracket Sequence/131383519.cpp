#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const pair<T, V> &x);
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
template <class T> void pr(const set<T>& pq);
 
template <class T, class V> void pr(const pair<T, V>& x) {
  cout << "{"; pr(x.first); cout << ", "; pr(x.second); cout << "}";
}
template <class T, class V> void pr(const map<T, V>& mp) {
  for(auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins
 
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
 
void test_case() {
  int N;
  cin >> N;
 
  vector<long long> C(N);
  for(auto &c : C)
    cin >> c;
 
  vector<long long> H = C;
 
  for(int i = 1; i < N; ++i) {
    H[i] = H[i-1] + (i % 2 ? -H[i] : H[i]);
  }
  SparseTable<long long> st(H);
  long long ans = 0;
 
  for(int i = 0; i < N; i += 2)
    for(int j = i + 1; j < N; j += 2) {
      if(j == i + 1) {
        ans += min(C[i], C[j]);
        continue;
      }
      long long mn = st.query(i + 1, j - 1);
      long long sub = max(H[j], (i == 0 ? 0 : H[i - 1]));
      ans += max(0LL, mn - sub + 1);
    }
 
  cout << ans;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  // cin >> tests;
 
  while(tests--) 
    test_case();
}