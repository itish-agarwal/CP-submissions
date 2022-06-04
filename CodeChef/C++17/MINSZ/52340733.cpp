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

long long get_first_one(long long n) {
  for(long long bit = 60; bit >= 0; --bit) {
    if(n & (1LL << bit)) {
      return bit;
    }
  }

  return 0;
}

void test_case() {
  long long C;
  cin >> C; 
  if(C == 0) {
    cout << 2 << '\n';
    cout << 1 << " " << 1 << '\n';
    return;
  }

  long long first_bit = get_first_one(C);
  vector<long long> changes{first_bit};

  for(long long bit = first_bit - 1; bit >= 0; --bit) {
    long long b1 = (C & (1LL << (bit + 1))) ? 1 : 0;
    long long b2 = (C & (1LL << bit)) ? 1 : 0;
    if(b1 ^ b2) {
      changes.push_back(bit);
    }
  }

  vector<long long> res;
  for(long long bit : changes)
    res.push_back((1LL << (bit + 1)) - 1);

  cout << (int) res.size() << '\n';
  for(long long r : res)
    cout << r << " ";

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