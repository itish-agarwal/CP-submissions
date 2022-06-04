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
const int MAX_N = 5e6 + 7;
const int mod = 998244353;
long long p[MAX_N];

long long power(long long a, long long b) {
  if(b == 0) 
    return 1;
 
  long long res = power(a, b / 2);
  res = ((long long) res * res) % mod;
  if(b % 2) 
    res = ((long long) res * a) % mod;
 
  return res;
}

void add_self(long long& a, long long b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

void test_case() {
  long long N, D;
  cin >> N >> D;

  long long ans = 0;
  for(long long d = 0; d < N; ++d) {
    if(d + D < N) {
      add_self(ans, (p[d] * p[D]) % mod);
    }
    if(D >= 2) {
      int lo = d + 1, hi = N - 1, mn = -1;
      while(lo <= hi) {
        int mid = (lo + hi) / 2;
        int other = D - mid + 2 * d;
        if((other > d && other < N) || mid >= d + D) {
          hi = mid - 1;
          mn = mid;
        }

        else {
          lo = mid + 1;
        }
      } 
      if(mn > -1) {
        int mx = D - mn + 2 * d;
        long long x = mx - mn + 1;
        add_self(ans, (((p[d] * x) % mod) * p[D - 2]) % mod);
      }
    }
  }

  cout << (2 * ans) % mod << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  p[0] = 1;
  for(int i = 1; i < MAX_N; ++i)
    p[i] = (2 * p[i - 1]) % mod;

  int tests = 1;
  // cin >> tests;

  while(tests--) 
    test_case();
}