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
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it); auto copy = it;
    if(++copy != mp.end()) 
      cout << " ";
  }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values;
  for(auto& value : pq) 
    values.push_back(value);

  pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) {
    pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : "");
  }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values;
  for(auto value : pq)
    values.push_back(value);

  pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins

void test_case() {
  long long N, M, X, Y;
  cin >> N >> M >> X >> Y;

  if(N == 1) {
    cout << X * (M - 1) << '\n';
    return;
  }

  if(M == 1) {
    cout << X * (N - 1) << '\n';
    return;
  }
  long long diagonal = min(N - 1, M - 1);
  long long ans = min(Y, 2 * X) * diagonal;
  ans += X * max(abs(N - diagonal - 1), abs(M - diagonal - 1));

  long long candidate = min(Y, 2 * X) * diagonal;
  long long left = max(N, M) - diagonal - 1;
  candidate += (left - left % 2) * Y;
  candidate += (left % 2) * X;

  ans = min(ans, candidate);
  // debug(candidate);
  cout << min(ans, X * (N + M - 2)) << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();

}