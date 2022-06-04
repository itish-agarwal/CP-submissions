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
const long long INF = 1e16 + 7;

void test_case() {
  int N, A, B;
  cin >> N >> A >> B;

  int p = 1, n = N, nn = N, pt = 0;
  while(n % 2 == 0) {
    p *= 2;
    n /= 2;
    pt++;
  }

  N /= p;
  // debug(N);

  long long best = -INF, candidate = 0, tt = 0;
  
  if(B > 0) {
    
    for(int x = 2; x * x <= N; ++x) {
      if(N % x == 0) {
        while(N % x == 0) {
          N /= x;
          tt++;
        }
      }
    }

    if(N > 1) {
      tt++;
    }
    candidate += tt * B;
  } 
  else {
    candidate += (N > 1) * B;

    long long maybe = min((long long)pt, tt) * A;
    if(pt > tt) {
      maybe += (A > 0 ? (pt - tt) * A : A);
    }
    else {
      maybe += B;
    }

    best = max(best, maybe);
  }

  if(A > 0) {
    candidate += pt * A;
  }
  else {
    candidate += (pt > 0) * A;
  }

  if(nn % 2 == 0) {
    candidate = max(candidate, (long long)A);
  }

  cout << max(best, candidate) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}