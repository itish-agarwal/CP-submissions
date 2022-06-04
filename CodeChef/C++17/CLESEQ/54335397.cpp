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

vector<int> compress(const vector<int> &a) {
  const int n = a.size();
  vector<int> res;
  for(int i = 0; i < n; ++i)
    if(i == 0 || a[i] != a[i-1])
      res.push_back(a[i]);

  return res;
}
void test_case() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for(auto &a : A) {
    cin >> a;
    a--;
  }

  A = compress(A);
  N = A.size();

  vector<int> cnt(K);
  for(int i = 0; i < N; ++i) {
    cnt[A[i]] += (i > 0 || i + 1 < N);
    if(i > 0 && i + 1 < N && A[i-1] == A[i+1])
      cnt[A[i]]++;
  }
  
  for(int i = 0; i < K; ++i)
    cout << (int) A.size() - 1 - cnt[i] << " ";

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}