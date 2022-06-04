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

long long mex_atleast_M(const vector<int> &values, int M) {
  const int n = values.size();
  long long res = 0;

  vector<int> freq(n + 1);
  int current = 0;

  int i = 0, j = -1;

  while(i < n) {
    while(j + 1 < n && current < M) {
      int prev = freq[values[++j]];
      freq[values[j]]++;
      if(values[j] < M && prev == 0) {
        current++;
      }
    }
    if(current == M) {
      res += n - j;
    }
    freq[values[i]]--;
    if(values[i] < M && freq[values[i]] == 0) {
      current--;
    }
    ++i;
  }

  return res;
}

void test_case() {
  int N;
  long long K;
  cin >> N >> K;

  K = (long long)N * (N + 1) / 2 - K + 1;

  vector<int> A(N);
  for(auto &a : A)
    cin >> a;

  int lo = 0, hi = N, ans = N;

  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    long long subarrays = mex_atleast_M(A, mid);
    if(subarrays >= K) {
      lo = mid + 1;
      ans = mid;
    }
    else {
      hi = mid - 1;
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