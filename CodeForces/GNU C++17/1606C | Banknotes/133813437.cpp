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
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
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
  pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
const long long INF = (long long) 2e18 + 7;
 
long long ceil_div(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b != 0);
}
 
void test_case() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N, 1);
  for(int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    for(int j = 0; j < a; ++j) {
      A[i] *= 10;
    }
  }
 
  sort(A.begin(), A.end());
  A.push_back((long long) 1e18);
 
  K++;
  long long ans = 0;
 
  for(int i = 0; i < N; ++i) {
    long long lft = A[i + 1] / A[i] - 1;
    long long take = min(lft, K);
    ans += A[i] * take;
    K -= take;
  }
  
  cout << ans << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  cin >> tests;
 
  while(tests--) 
    test_case();
}