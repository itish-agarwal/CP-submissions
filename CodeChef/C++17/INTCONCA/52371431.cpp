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

int digits(int n) {
  int res = 0;
  while(n > 0) {
    n /= 10;
    res++;
  }

  return res;
}

void test_case() {
  int N;
  long long L, R;
  cin >> N >> L >> R;

  vector<int> A(N);
  for(auto &a : A)
    cin >> a;

  sort(A.begin(), A.end());
  vector<vector<long long>> cnt(10, vector<long long> (N));

  for(int l = 1; l <= 9; ++l) {
    long long M = 1;
    for(int x = 0; x < l; ++x) {
      M *= 10;
    }
    for(int i = 0; i < N; ++i) {
      cnt[l][i] = M * A[i];
    }
  }

  long long ans = 0;

  for(auto &a : A) {
    long long LL = L - a, RR = R - a;
    int len = digits(a);

    int r = upper_bound(cnt[len].begin(), cnt[len].end(), RR) - cnt[len].begin() - 1;
    int l = lower_bound(cnt[len].begin(), cnt[len].end(), LL) - cnt[len].begin();

    ans += max(0, r - l + 1);
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