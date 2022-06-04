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

long long ceil_div(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b != 0);
}
void test_case() {
  long long a, b, X;
  cin >> a >> b >> X;

  long long k0 = ceil_div(X, a) + (ceil_div(X, a) * a) % 2;
  long long k1 = ceil_div(X, b) + (ceil_div(X, b) * b) % 2;
  long long ans = min(k0, k1);

  for(int take = 0; take <= 10; take++) {
    if(a * take <= X) {
      long long Xk = X - a * take;
      long long can = take + ceil_div(Xk, b) + (ceil_div(Xk, b) * b) % 2;
      long long val = a * take + ceil_div(Xk, b) * b;
      ans = min(ans, can + val % 2);
    }
  }

  for(int take = 0; take <= 10; take++) {
    if(b * take <= X) {
      long long Xk = X - b * take;
      long long can = take + ceil_div(Xk, a) + (ceil_div(Xk, a) * a) % 2;
      long long val = b * take + ceil_div(Xk, a) * a;
      ans = min(ans, can + val % 2);
    }
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