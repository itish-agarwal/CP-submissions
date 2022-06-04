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
const int INF = 2e9 + 7;
 
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
  int N;
  cin >> N;
  vector<int> A(N + 1), B(N + 1);
  for(int i = 1; i <= N; ++i)
    cin >> A[i];
  for(int i = 1; i <= N; ++i)
    cin >> B[i];
 
  vector<int> d(N + 1, INF), parent(N + 1, -1);
  d[N] = 0;
 
  queue<pair<int, int>> q;
  q.push({N, N});
 
  set<int> not_rested;
  for(int i = 0; i < N; ++i)
    not_rested.insert(i);
 
  while(!q.empty()) {
    int x = q.front().first;
    int slipped_from = q.front().second;
 
    q.pop();
 
    auto it = not_rested.lower_bound(x - A[x]);
 
    while(it != not_rested.end() && *it <= x) {
      int final_position = *it + B[*it];
      if(d[x] + 1 < d[final_position]) {
        d[final_position] = d[x] + 1;
        q.push({final_position, *it});
        parent[*it] = slipped_from;
      }
      not_rested.erase(it++);
    }
  }
 
  if(d[0] >= INF) {
    cout << -1 << '\n';
    return;
  }
 
  int a = 0;
  vector<int> result;
  while(a < N) {
    result.push_back(a);
    a = parent[a];
  }
 
  reverse(result.begin(), result.end());
  cout << (int) result.size() << '\n';
  print_vector(result);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  // cin >> tests;
 
  while(tests--) 
    test_case();
}