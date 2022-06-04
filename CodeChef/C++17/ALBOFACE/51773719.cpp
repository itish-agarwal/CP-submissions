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
const int nax = 1e3 + 5;
int dp[nax];

void test_case() {
  long long N;
  cin >> N;

  if(N <= 1000) {
    cout << (dp[N] ? "Alice" : "Bob") << '\n';
    return;
  }

  if((N & (N - 1)) == 0) {
    cout << "Alice" << '\n';
    return;
  }

  long long p = 1;
  while(p <= N)
    p *= 2;

  if(N + 1 == p) {
    cout << "Alice" << '\n';
    return;
  }

  if(p - 3 <= N && N <= p - 2) {
    cout << "Bob" << '\n';
    return;
  }

  int diff = p - N + 1;
  cout << (diff % 2 ? "Alice" : "Bob") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 1; i < nax; ++i) {
    if(i % 2 == 0) {
      int n = i;
      while(n % 2 == 0) {
        dp[i] |= !dp[n / 2];
        n /= 2;
      }
    }
    else {
      dp[i] = !dp[i - 1];
    }
  }

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}