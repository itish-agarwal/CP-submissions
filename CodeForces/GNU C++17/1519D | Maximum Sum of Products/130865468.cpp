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
 
void test_case() {
  int N;
  cin >> N;
 
  vector<long long> A(N), B(N);
  for(auto &a : A)
    cin >> a;
 
  for(auto &b : B)
    cin >> b;
 
  long long init = 0;
  for(int i = 0; i < N; ++i)
    init += A[i] * B[i];
 
  long long ans = init;
  
  for(int c = 0; c < N; ++c) {
    long long candidate = init;
 
    for(int x = c - 1, y = c + 1; x >= 0 && y < N; x--, y++) {
      candidate -= A[x] * B[x] + A[y] * B[y];
      candidate += A[x] * B[y] + A[y] * B[x];
 
      ans = max(ans, candidate);
    }
  }
 
  for(int c = 0; c < N - 1; ++c) {
    long long candidate = init;
 
    for(int x = c, y = c + 1; x >= 0 && y < N; x--, y++) {
      candidate -= A[x] * B[x] + A[y] * B[y];
      candidate += A[x] * B[y] + A[y] * B[x];
 
      ans = max(ans, candidate);
    }
  }
 
  cout << ans << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  // cin >> tests;
 
  while(tests--) 
    test_case();
}