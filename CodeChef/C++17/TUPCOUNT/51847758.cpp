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

const int MAX_N = 1e6 + 7;
long long phi[MAX_N];

void test_case() {
  long long N;
  cin >> N;

  long long ans = 0;
  for(int x = 1; x <= N; ++x) {
    long long tt = N / x;
    ans += phi[x] * tt * tt;
  }

  cout << 2 * ans - N * N << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int p = 1; p < MAX_N; ++p)
    phi[p] = p;

  for(int p = 2; p < MAX_N; ++p)
    if(phi[p] == p) {
      phi[p] = p - 1;
      for(int j = 2 * p; j < MAX_N; j += p) {
        phi[j] *= (p - 1);
        phi[j] /= p;
      }
    }

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}

