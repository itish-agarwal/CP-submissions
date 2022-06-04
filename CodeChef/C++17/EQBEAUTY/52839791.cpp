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
using ll = long long;
const ll INF = 2e17 + 9;

ll calculate(ll mn1, ll mx1, ll mn2, ll mx2) {
  return abs((mx1 - mn1) - (mx2 - mn2));
}

void test_case() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for(auto &a : A)
    cin >> a;

  sort(A.begin(), A.end());

  ll ans = INF;

  if(N > 3) {
    multiset<ll> s;
    for(int i = 1; i < N; ++i)
      s.insert(A[i]);

    for(int i = 1; i < N; ++i) {
      s.erase(s.find(A[i]));
      ll rem_maximum = (i == N - 1 ? A[N-2] : A[N-1]);
      s.erase(s.find(rem_maximum));

      ll x = rem_maximum - (A[i] - A[0]);

      auto lb = s.lower_bound(x);
      if(lb != s.end()) 
        ans = min(ans, *lb - x);

      auto up = s.upper_bound(x);
      if(up != s.begin()) 
        ans = min(ans, x - *prev(up));

      s.insert(A[i]);
      s.insert(rem_maximum);
    }
  }

  ll candidate = 0;
  for(int i = 0; i < N - 1; ++i)
    candidate += abs(A[i] - A[(N-1) / 2]);

  ans = min(ans, candidate);
  candidate = 0;
  for(int i = 1; i < N; ++i)
    candidate += abs(A[i] - A[N/2]);

  cout << min(ans, candidate) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}