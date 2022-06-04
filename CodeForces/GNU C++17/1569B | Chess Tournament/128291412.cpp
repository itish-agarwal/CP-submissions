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
  string S;
  cin >> N >> S;
 
  vector<int> twos;
  for(int i = 0; i < N; ++i)
    if(S[i] == '2') 
      twos.push_back(i);
 
  if(twos.empty()) {
    cout << "YES" << '\n';
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) { 
        cout << (i == j ? 'X' : '=');
      }
      cout << '\n';
    }
    return;
  }
 
  if((int) twos.size() <= 2) {
    cout << "NO" << '\n';
    return;
  }
 
  vector<string> res(N, string(N, '='));
 
  for(int i = 0; i < N; ++i)
    res[i][i] = 'X';
 
  for(int i = 1; i < (int) twos.size(); ++i) {
    res[twos[i-1]][twos[i]] = '+';
    res[twos[i]][twos[i-1]] = '-';
  }
 
  res[twos.back()][twos[0]] = '+';
  res[twos[0]][twos.back()] = '-';
  
  cout << "YES" << '\n';
 
  for(auto& row : res)
    cout << row << '\n';
} 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();
 
}