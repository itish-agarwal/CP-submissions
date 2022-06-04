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
 
bool not_intersect(const pair<int, int> &a, const pair<int, int> &b) {
  return b.first > a.second;
}
 
void test_case() {
  int N, K;
  cin >> N >> K;
 
  int total_xor = 0;
  vector<int> A(N);
 
  for(auto &a : A) {
    cin >> a;
    total_xor ^= a;
  }
 
  vector<vector<int>> edges(N);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
 
  if(total_xor == 0) {
    cout << "YES" << '\n';
    return;
  }
 
  if(N - 1 < 2 || K - 1 < 2) {
    cout << "NO" << '\n';
    return;
  } 
 
  vector<int> tour;
 
  function<void(int, int)> Dfs = [&](int a, int pr) {
    tour.push_back(a);
    for(int b : edges[a])
      if(b != pr)
        Dfs(b, a);
 
    tour.push_back(a);
  };  
 
  Dfs(0, -1);
  vector<int> beg(N, -1), en(N);
 
  for(int i = 0; i < 2 * N; ++i) {
    en[tour[i]] = i;
    if(beg[tour[i]] == -1)
      beg[tour[i]] = i;
  }
 
  vector<int> preffix_xors(2 * N);
  for(int i = 0; i < N; ++i) 
    preffix_xors[beg[i]] = A[i];
 
  for(int i = 1; i < 2 * N; ++i)
    preffix_xors[i] ^= preffix_xors[i - 1];
 
  auto get_xor = [&](int L, int R) {
    return preffix_xors[R] ^ (L > 0 ? preffix_xors[L - 1] : 0);
  };  
 
  vector<int> subtree_xor(N), good_count(N), good(N);
 
  function<void(int, int)> dfs = [&](int a, int pr) {
    subtree_xor[a] = A[a];
    for(int b : edges[a]) 
      if(b != pr) {
        dfs(b, a);
        subtree_xor[a] ^= subtree_xor[b];
        good_count[a] += good_count[b];
      }
 
    good[a] = subtree_xor[a] == total_xor;
    good_count[a] += good[a];
  };
 
  dfs(0, -1);
 
  vector<pair<int, int>> intervals;
 
  for(int i = 1; i < N; ++i) 
    if(good[i])
      intervals.push_back({beg[i], en[i]});
 
  
  sort(intervals.begin(), intervals.end());
 
  vector<int> start_points;
  for(auto it : intervals)
    start_points.push_back(it.first);
 
  // debug(intervals);
 
  for(auto [l, r] : intervals) {
    int in = upper_bound(start_points.begin(), start_points.end(), r) - start_points.begin();
    if(in >= 0 && in < (int) intervals.size()) {
      cout << "YES" << '\n';
      return;
    }
  }
 
  for(int i = 1; i < N; ++i)
    if(subtree_xor[i] == 0 && good_count[i] > 0) {
      cout << "YES" << '\n';
      return;
    }
 
  cout << "NO" << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  cin >> tests;
 
  while(tests--) 
    test_case();
}