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
  int N, X, Y;
  cin >> N >> X >> Y;

  vector<int> S(N), E(N);

  for(int i = 0; i < N; ++i)
    cin >> S[i] >> E[i];

  vector<int> V(X), W(Y);
  for(auto &v : V)
    cin >> v;

  for(auto &w : W)
    cin >> w;

  sort(V.begin(), V.end());
  sort(W.begin(), W.end());

  debug(V, W);

  int ans = 2e9 + 7;

  for(int i = 0; i < N; ++i) {
    int in0 = upper_bound(V.begin(), V.end(), S[i]) - V.begin() - 1;
    int in1 = lower_bound(W.begin(), W.end(), E[i]) - W.begin();

    if(in0 >= 0 && in1 >= 0 && in1 < (int) W.size()) 
      ans = min(ans, W[in1] - V[in0] + 1);
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