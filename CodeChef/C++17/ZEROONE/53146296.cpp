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

void test_case() {
  int N;
  cin >> N;

  vector<int> ones, zeros;
  for(int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if(i % 2 == 0)
      zeros.push_back(a);
    else
      ones.push_back(a);
  }

  sort(zeros.rbegin(), zeros.rend());
  sort(ones.begin(), ones.end());

  int i0 = 0, i1 = 0;
  for(int i = 0; i < N; ++i) 
    cout << (i % 2 == 0 ? zeros[i0++] : ones[i1++]) << " ";

  cout << '\n';

  i0 = 0, i1 = 0;
  long long subsequences = 0, ones_left = accumulate(ones.begin(), ones.end(), 0LL);

  for(int i = 0; i < N; ++i) {
    if(i % 2 == 0) {
      long long zz = zeros[i0];
      subsequences += zz * ones_left; 
      i0++;
    }
    else {
      ones_left -= ones[i1];
      i1++;
    }
  }

  cout << subsequences << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}