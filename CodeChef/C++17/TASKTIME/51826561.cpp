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

void test_case() {
  int N, M, K;
  cin >> N >> M >> K;

  vector<int> C(N), T(N);
  for(auto &c : C) {
    cin >> c;
    c--;
  }

  for(auto& t : T)
    cin >> t;

  vector<vector<int>> courses(M);
  for(int i = 0; i < N; ++i)
    courses[C[i]].push_back(T[i]);

  for(int i = 0; i < M; ++i)
    sort(courses[i].begin(), courses[i].end());

  vector<int> all;
  for(auto v : courses) 
    if(!v.empty()) {
      all.push_back(v[0]);

      for(int j = 1; j + 1 < (int) v.size(); j += 2) 
        all.push_back(v[j] + v[j + 1]);
    }
  

  sort(all.begin(), all.end());

  int iter = -1;
  while(iter + 1 < (int) all.size() && K >= all[iter + 1]) {
    K -= all[++iter];
  }

  cout << iter + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}