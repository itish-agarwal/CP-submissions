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
const long long nax = 1e6 + 7;
 
void test_case() {
  int N;
  cin >> N;
 
  vector<int> A(N);
  map<int, int> freq;
 
  for(auto &a : A) {
    cin >> a;
    freq[a]++;
  }
 
  for(auto it : freq)
    if(2 * it.second >= N) {
      cout << -1 << '\n';
      return;
    }
 
  sort(A.begin(), A.end());
  int ans = 1;
 
  auto works = [&](int x) { 
    vector<int> rems;
    for(auto &a : A)
      rems.push_back((a + x * nax) % x);
 
    sort(rems.begin(), rems.end());
    int i = 0, j = -1, best = 1;
 
    while(i < N) {
      while(j + 1 < N && rems[j+1] == rems[i])
        ++j;
 
      best = max(best, j - i + 1);
      i = j + 1;
    }
 
    return 2 * best >= N;
  };
 
  for(int i = 0; i < N; ++i)
    for(int j = i + 1; j < N; ++j) {
      int d = A[j] - A[i];
      for(int x = 1; x * x <= d; ++x) {
        if(d % x == 0) {
          if(works(x)) ans = max(ans, x);
          if(works(d / x)) ans = max(ans, d / x);
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