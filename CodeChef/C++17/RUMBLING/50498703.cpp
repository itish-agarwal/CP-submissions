#include <bits/stdc++.h>

using namespace std;
using namespace chrono;
#define int long long

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
// void pr(long long x)  { cout << x; }
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

const int INF = 2e17 + 9;

void test_case() {
  int N, X, Y;
  string S;

  cin >> N >> S >> X >> Y;

  vector<int> east(N), west(N);

  for(int i = 0; i < N; ++i) {
    if(S[i] == 'W') 
      east[i] = 2 * min(X, Y);
    else if(S[i] == 'N') 
      east[i] = min(X, 3 * Y);
    else if(S[i] == 'S') 
      east[i] =  min(3 * X, Y);
  }

  for(int i = 0; i < N; ++i) {
    if(S[i] == 'E') 
      west[i] = 2 * min(Y, X);
    else if(S[i] == 'N') 
      west[i] = min(Y, 3 * X);
    else if(S[i] == 'S')
      west[i] = min(3 * Y, X);
  }

  for(int i = 1; i < N; ++i) 
    east[i] += east[i - 1];

  for(int i = N - 2; i >= 0; --i)
    west[i] += west[i + 1];


  int ans = min(east[N - 1], west[0]);

  for(int i = 0; i < N; ++i) {
    ans = min(ans, east[i] + (i + 1 < N ? west[i + 1] : 0));
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