#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif

#define int long long

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
// void pr(int x)  { cout << x; }

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

int operations(long long x1, long long y1, long long x2, long long y2) {
  if(x1 == x2 && y1 == y2) 
    return 0;

  if(x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 -y2)) 
    return 1;

  return 2;
}

void test_case() {
  int N;
  cin >> N;
  vector<long long> X(N), Y(N);

  for (auto &x : X) {
    cin >> x;
    x *= 2;
  }

  for (auto &y : Y) {
    cin >> y;
    y *= 2;
  }

  int ans = 2e9 + 7;

  for (int i = 0; i < N; ++i) {
    int candidate = 0;
    for (int j = 0; j < N; ++j) {
      candidate += operations(X[i], Y[i], X[j], Y[j]);
    }

    ans = min(ans, candidate);
  }

  auto update = [&](long long xf, long long yf) {
    int candidate = 0;
    for (int i = 0; i < N; ++i)
      candidate += operations(X[i], Y[i], xf, yf);

    ans = min(ans, candidate);
  };

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if(i ^ j) {
        long long a = X[i], b = Y[i], c = X[j], d = Y[j];
        update(a + b - d, d);
        update(c, a + b - c);
        update((a + b + c - d) / 2, (a + b + d - c) / 2);
        update(a - b + d, d);
        update(c, c - a + b);
        update((a - b + c + d) / 2, (b - a + c + d) / 2);
        update(a, d);
        update(a, a - c + d);
        update(a, c + d - a);
        update(c, d);
        update(b + c - d, b);
        update(c + d - b, b);
      }
    }
  }

  cout << ans << '\n';
} 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests;
  cin >> tests;
  while(tests--)
    test_case();

}