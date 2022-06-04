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

template <class T> 
ostream& operator << (ostream& stream, const vector<T>& values) {
  for(T v : values) 
    cout << v << " ";

  return stream;
}
template <class T>
void print_vector(const vector<T>& values, int from = -1, int to = -1) {
  if(from < 0) from = 0;
  if(to < 0) to = int(values.size()) - 1;

  for(int i = from; i <= to; ++i) 
    cout << values[i] << (i < to ? ' ' : '\n');
}

void test_case() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  
  int max_jumps = 0;
  char prev = S[0];

  for(int i = 1; i < N; ++i) 
    if(S[i] != prev) {
      max_jumps += 1;
      prev = S[i];
    }  

  if(max_jumps < K) {
    cout << -1 << '\n';
    return;
  }

  vector<int> same, diff;
  for(int i = 1; i < N; ++i) {
    if(S[i] == S[0])
      same.push_back(i);

    else
      diff.push_back(i);
  }
  int i = 0, j = 0, color = S[0] - '0', at = 0;

  for(int r = 0; r < K - 1; ++r) {
    if(color == S[0] - '0') {
      at = diff[i++];
    }
    else {
      at = same[j++];
    }
    color ^= 1;
  }

  for(int i = N - 1; i > at; --i) 
    if(S[i] - '0' != color) {
      cout << i + 1 << '\n';
      return;
    }
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();

}