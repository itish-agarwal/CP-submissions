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
int N, X, Y, INF = 2e5 + 7;
int A[302], B[302], dp[302][400][400];

int rec(int i, int a_sum, int b_sum) {
  if(i == N) 
    return (a_sum >= X && b_sum >= Y ? 0 : INF);

  if(a_sum >= X && b_sum >= Y) 
    return 0;

  if(dp[i][a_sum][b_sum] > -1)
    return dp[i][a_sum][b_sum];

  int res = rec(i + 1, a_sum, b_sum);

  int pos = rec(i + 1, min(X, a_sum + A[i]), min(Y, b_sum + B[i]));

  if(pos < INF)
    res = min(res, 1 + pos);

  return dp[i][a_sum][b_sum] = res;
}

void test_case() {
  cin >> N >> X >> Y;
  for(int i = 0; i < N; ++i)
    cin >> A[i] >> B[i];

  memset(dp, -1, sizeof(dp));
  int ans = rec(0, 0, 0);

  cout << (ans >= INF ? -1 : ans) << '\n';
}   

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();

}