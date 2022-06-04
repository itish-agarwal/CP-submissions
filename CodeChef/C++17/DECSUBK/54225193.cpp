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
int LIS(const vector<int>& a) {
  const int n = a.size();
  multiset<int> pq;
  for(auto &el : a) {
    pq.insert(el);
    auto it = pq.upper_bound(el);
    if(it != pq.end())
      pq.erase(it);
  }

  return (int) pq.size();
}
void test_case() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for(auto &a : A)
    cin >> a;

  map<int, int> freq;
  for(auto &a : A)
    freq[a]++;

  for(auto [el, ff] : freq)
    if(ff > K) {
      cout << -1 << '\n';
      return;
    }

  sort(A.begin(), A.end());
  vector<int> result;

  int remaining = N, p = -1;
  while(remaining > 0) {
    for(int i = 0; i < N; ++i) {
      if(A[i] > 0) {
        vector<int> a, b;
        vector<int> S0 = result, S1 = result;
        S0.push_back(A[i]);
        S1.push_back(A[i]);
        for(int j = 0; j < N; ++j)
          if(j != i && A[j] > 0) 
            a.push_back(A[j]);

        b = a;
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        for(auto &el : a)
          S0.push_back(el);

        for(auto &el : b)
          S1.push_back(el);

        int K0 = LIS(S0), K1 = LIS(S1);

        if(K1 <= K && K <= K0) {
          result.push_back(A[i]);
          remaining--;
          A[i] = -1;
          break;
        }
      }
    }
  }

  print_vector(result);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}