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
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
 
  vector<int> good{-1};
 
  for(int i = 0; i < N; ++i)
    if(S[i] != T[i]) 
      good.push_back(i);
 
  good.push_back(N);
 
  int ans = 2 * ((int) good.size() - 2);
  
  vector<int> taken(N);
 
  for(int i = 1; i < (int) good.size(); ++i) {
    int l = good[i - 1] + 1, r = good[i] - 1;
    if(r >= l) {  
      for(int j = l + 1; j <= r; ++j) {
        if(S[j] != S[j - 1] && !taken[j] && !taken[j - 1]) {
          taken[j] = taken[j - 1] = 1;
          ans += 2;
        }
      }
 
      for(int j = l; j <= r; ++j) {
        if(S[j] == '0' && !taken[j]) {
          taken[j] = 1;
          ans += 1;
        }
      }
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